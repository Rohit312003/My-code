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
int val[600][600];
int level[600][600];
int vis[600][600];
int n, m;

vector<pair<int,int>> movements={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
bool isval(int x,int y){


    return x>=0&&y>=0&&x<n&&y<m;
}
int bfs()
{
    int maxo = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxo = max(maxo, val[i][j]);
        }
    }
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maxo == val[i][j])
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                    level[i][j] = 0;
                }
            }
        }
int ans=0;
        while(!q.empty()){
int cx=q.front().first;
int cy=q.front().second;
q.pop();

for(auto movement:movements){

    int x=cx+movement.first;
    int y=cy+movement.second;

    if(!isval(x,y))continue;
if(vis[x][y])continue;

level[x][y]=1+level[cx][cy];
vis[x][y]=1;
q.push({x,y});
if(ans<level[x][y]){
    ans=level[x][y];
}


}


        }

        return ans;
    }
    void reset()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                level[i][j] = INF;
                vis[i][j] = 0;
            }
        }
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

            cin >> n >> m;
 reset();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cin >> val[i][j];
                }
            }

            cout << bfs() << endl;
           
        }
        return 0;
    }