#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
#define MOD 1000000007;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
int vis[10][10];
int level[10][10];

int getx(string s)
{
    return s[0] - 'a';
}
int gety(string s)
{
    return s[1] - '1';
}
bool valid(int x, int y)
{

    return x >= 0 && y >= 0 && x < 8 && y < 8;
}
vector<pair<int, int>> movments = {
    {-1, -2}, {1, 2}, {-1, 2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}};
int bfs(string s1, string s2)
{
    int sx = getx(s1);
    int sy = gety(s1);
    int ex = getx(s2);
    int ey = gety(s2);
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first;
        int y = v.second;
        q.pop();

        for (auto move : movments)
        {
            int childx = move.first + x;
            int childy = move.second + y;
            if (!valid(childx, childy))
                continue;

            if (!vis[childx][childy])
            {
                q.push({childx, childy});
                level[childx][childy] = 1 + level[x][y];
                vis[childx][childy] = 1;
            }
        }
    }

    return level[ex][ey];
}
void reset()
{
    memset(level, 0, sizeof(level));
    memset(vis, 0, sizeof(vis));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {

        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
        for (int i = 0; i < 8; i++)
        {

            for (int j = 0; j < 8; j++)
            {
                cout << level[i][j] << " ";
            }
            cout << endl;
        }
        reset();
    }

    return 0;
}