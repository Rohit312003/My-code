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
vector<pair<int, int>> g[N];
int poww(int a, int y)
{
    if (y == 0)
    {
        return 1;
    }
    long long x = poww(a, y / 2);
    if (y % 2 == 0)
    {
        return (x * x) % MOD;
    }
    else
    {
        return (a * (x * x)) % MOD;
    }
}
// in prefix sum indexing startfrom 1 based:)
int solve(int n,vector<vector<int>> &cost){

    vector<int> dp((1<<n),15000);
    dp[0]=0;
    
 
    for(int i=0;i<(1<<n);i++){
      int count=__builtin_popcount(i);
      
      
        for(int bit=0;bit<n;bit++){
          
            if(!(i&(1<<bit))){
                dp[(i|(1<<bit))]=min(dp[(i|(1<<bit))],dp[i]+cost[count][bit]);
                
          }
        }
    }
   
    return dp[(1<<n)-1];
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
        int n;
        cin >> n;
        vector<vector<int>> cost;

        for (int i = 0; i < n; i++)
        {

            vector<int> temp(n);
            for (int j = 0; j < n; j++)
            {
                cin >> temp[j];
            }
            cost.push_back(temp);
        }

           for (int i = 0; i < n; i++)
        {

            
            for (int j = 0; j < n; j++)
            {
                cout<< cost[i][j]<<" ";
            }
            cout<<endl;
         
        }


        cout<<solve(n,cost);
    }
    return 0;
}
