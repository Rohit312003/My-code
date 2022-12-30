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
vector<int> dist(N, INF);
vector<int> g[N];
int poww(int x, int y)
{
    int a = 1;
    while (y--)
    {
        a *= x;
    }
    return a;
}
map<int, int> prnt;
void dfs(int v, int p)
{
    prnt[v] = p;
    vis[v] = 1;

    for (auto child : g[v])
    {

        if (vis[child])
        {
            continue;
        }

        dfs(child, v);
    }
}
vector<int> parent(int v)
{

    vector<int> ans;
    ans.push_back(v);
    while (prnt[v])
    {

        ans.push_back(prnt[v]);
        v = prnt[v];
    }
    return ans;
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
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);
    vector<int> ans;

    for (auto i : prnt)
    {
        cout << i.first << " " << i.second << endl;
    }
    int x, y;
    cin >> x >> y;
    vector<int> an1, an2;

    an1 = parent(x);
    an2 = parent(y);

    // for (int i = 0; i < an1.size(); i++)
    // {
    //     cout << an1[i] << endl;
    // }

    // for (int i = 0; i < an2.size(); i++)
    // {
    //     cout << an2[i] << endl;
    // }
    reverse(an1.begin(),an1.end());
    reverse(an2.begin(),an2.end());
    if (an1.size() < an2.size())
    {
        for (int i = 0; i <an1.size() ; i++)
        {
            if(an1[i]!=an2[i]){
                cout<<an1[i];
                return 0;
            }
        }
    }else{
        for (int i = 0; i <an2.size() ; i++)
        {
            if(an1[i]!=an2[i]){
                cout<<an1[i-1];
                return 0;
            }
        }
    }

    return 0;
}