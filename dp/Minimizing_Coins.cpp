#include<bits/stdc++.h>
#include<string>
#include<math.h>
#include<string.h>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
#define MOD 1000000007;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<int> vis(N, 0);
int mdd=1e9+7;
vector<int> dist(N, INF);
 vector<pair<int, int>> g[N];
int poww(int a, int y){if (y == 0){return 1;}long long x = poww(a, y / 2);if (y % 2 == 0){return (x * x) % MOD;}else{ return (a * (x * x)) % MOD;}}
//in prefix sum indexing startfrom 1 based:) 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   ll n,a;
   cin>>n>>a;
   vector<int> coin;

   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    coin.push_back(x);
   }
   vector<ll> dp(a+2,INT_MAX);
dp[0]=0;
   for(int i=1;i<=a;i++){

for(int j=0;j<n;j++){
if((i-coin[j])>=0){
dp[i]=min(1+dp[i-coin[j]],dp[i]);
}
}



   }



if(dp[a]>=INT_MAX){
cout<<-1;
}else{
    cout<<dp[a];
}

 
   return 0;
}