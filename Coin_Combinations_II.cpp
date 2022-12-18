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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // dp states 2
    int n, x;

    cin >> n >> x;

    vector<int> coin(n+1);

    for (int i = 1; i <= n; i++)
    {

        cin >> coin[i];
    }

    int dp[n+1][x+5];


for(int i=1;i<=n;i++){

    for(int j=0;j<=x;j++){

        if(j==0){

            dp[i][j]=1;
        }else{

int ans1=(i==1)?0:dp[i-1][j];
int ans2=(coin[i]>j)?0:dp[i][j-coin[i]];
dp[i][j]=(ans1+ans2)%MOD;
        }


}}

cout<<dp[n][x];

        return 0;
}