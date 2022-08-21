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
int vis[9][9];
int level[9][9];
vector<pair<int, int>> movement = {
    {-1, -2}, {1, 2}, {-1, 2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}};
vector<int> dist(N, INF);
vector<pair<int, int>> g[N];
int getx(string s)
{

    return s[0] - 'a';
}
bool valid(int x, int y)
{

    return x >= 0 && y >= 0 && x < 8 && y < 8;
}
int gety(string s)
{

    return s[1] - '1';
}
int dfs(string s1, string s2)
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

        for (auto move : movement)
        {

            int childx = x + move.first;
            int childy = move.second + y;
            if (!valid(childx, childy))
                continue;

            if (!vis[childx][childy])
            {
                q.push({childx, childy});
                vis[childx][childy] = 1;
                level[childx][childy] = 1 + level[x][y];
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
        cout << dfs(s1, s2)<<endl;
        reset();
    }
    return 0;
}