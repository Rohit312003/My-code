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

    ll t;
    cin >> t;

    vector<ll> dp(t + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= t; i++)
    {

        for (int j = 1; j <= 6; j++)
        {
            if ((i - j) >= 0)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[t] << endl;

    return 0;
}