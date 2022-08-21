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
  vector<int> dist(N, INF);
vector<pair<int, int>> g[N];  
void dijkstra(int source)
{    
   
    set<pair<int,int>> st;
    // set(wt,node)
    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {

      auto node=*st.begin();
        int c = node.second;
        int c_dis = node.first;
        st.erase(st.begin());
        if (vis[c])
            continue;
        vis[c] = 1;

        for (auto child : g[c])
        {
            int child_v = child.first;
            int child_wt = child.second;

            if (dist[c] + child_wt < dist[child_v])
            {

                dist[child_v] = dist[c] + child_wt;
                 st.insert({dist[child_v],child_v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        // directed graph
        g[x].push_back({y, wt});
    }
    dijkstra(1);
cout<<dist[5];

    return 0;
}