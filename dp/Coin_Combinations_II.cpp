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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a;
    cin >> n >> a;
    vector<int> coin(n + 1);

    for (int i = 1; i <= n; i++)
    {

        cin >> coin[i];
    }

    int dp[n+2][a+5];

    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j <= a; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int op1 = (coin[i] > j) ? 0 : dp[i][j - coin[i]]; /*if we take this element*/
                int op2 = (i == 1) ? 0 : dp[i - 1][j];            /*if we have only one element we cannot refuse it*/
                dp[i][j] = (op1 + op2) % MOD;
            }
        }
    }
    cout << dp[n][a];
    return 0;
}