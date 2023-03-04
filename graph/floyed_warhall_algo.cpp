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
vector<int> vis(N, 0);
int mdd = 1e9 + 7;
vector<vector<int>> dist(1000, vector<int>(1000, INF));
vector<pair<int, int>> g[N];
int poww(int x, int y)
{
    int a = 1;
    while (y--)
    {
        a *= x;
    }
    return a;
}
//  all pair shortest path
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 1; i <= v; i++)
        {

            for (int j = 1; j <= v; j++)
            {

                if (i == j)
                {
                    dist[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < e; i++)
        {

            int x, y, wt;
            cin >> x >> y >> wt;

            dist[x][y] = wt;
        }

        for (int k = 1; k <= v; k++)
        {

            for (int i = 1; i <= v; i++)
            {

                for (int j = 1; j <= v; j++)
                {

                    
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    
                }
            }
        }

        for (int i = 1; i <= v; i++)
        {

            for (int j = 1; j <= v; j++)
            {

                cout << dist[i][j] << " ";
            }
            cout << endl;
        }

        cout<<dist[1][3]<<endl;
    }
    return 0;
}