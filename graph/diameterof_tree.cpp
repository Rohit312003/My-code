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
#define const int N = 10000;

vector<int> g[10000];
int depth[1000];
void dfs(int v, int p)
{

    for (int child : g[v])
    {

        if (child == p)
        {
            continue;
        }
depth[child]+=depth[v]+1;
        dfs(child, v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v;
    cin >> v;
    for (int i = 0; i < v - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    int maxo=INT_MIN;
    int inm=-1;
for (int i = 1; i <= v ; i++)
    {
    
if(maxo<depth[i]){
maxo=depth[i];
inm=i;

}
//for make the depth arry use again in next dfs call 
depth[i]=0;

    }

    dfs(inm,0);
    for (int i = 1; i <= v ; i++)
    {
       
if(maxo<depth[i]){
maxo=depth[i];


}

    }

    cout<<maxo;
    return 0;
}