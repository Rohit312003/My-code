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
int poww(int x, int y)
{
  int a = 1;
  while (y--)
  {
    a *= x;
  }
  return a;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<string> s(n);

  for (int i = 0; i < n; i++)
  {

    cin >> s[i];
  }

  // no dp states=2


  int dp[n + 1][n + 1];

  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= n; j++)
    {
      if (i == 1 && j == 1)
      {
       
         if (s[i-1][j-1] == '*')
        {

          dp[i][j] = 0;
        }else{
           dp[i][j] = 1;
        }
      }
      else
      {
        
       
          int ans1 = (i - 1 == 0) ? 0 : dp[i - 1][j];

          int ans2 = (j - 1 == 0) ? 0 : dp[i][j - 1];

          dp[i][j] = (ans1 + ans2)%MOD;
          if (s[i-1][j-1] == '*')
        {

          dp[i][j] = 0;
        }
        
      }
    }
  }

cout<<dp[n][n]<<endl;
  return 0;
}
