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
ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
ll dp[10][80][2];
bool valid(ll p)
{
    for (int i = 0; i < 24; i++)
    {
        if (p == prime[i])
        {
            return 1;
        }
    }

    return 0;
}
ll digi(string s, ll pos, ll sum, ll tight)
{

    if (pos == s.length())
    {

        if (valid(sum))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }else if(dp[pos][sum][tight]!=-1){

    return dp[pos][sum][tight];
  }else if (tight == 1)
    {
        ll res = 0;
        for (int i = 0; i <= (s[pos] - '0'); i++)
        {

            if (i == (s[pos] - '0'))
            {
                res += digi(s, pos + 1, sum + i, 1);
            }
            else
            {
                res += digi(s, pos + 1, sum + i, 0);
            }
        }
        return dp[pos][sum][tight]=res;
    }
    else
    {
        ll res = 0;
        for (int i = 0; i <= 9; i++)
        {

            res += digi(s, pos + 1, sum + i, 0);
        }

        return dp[pos][sum][tight]=res;
    }
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

        ll l, r;

        cin >> l >> r;
        l = l - 1;
        string a = to_string(l);
        string b = to_string(r);
        memset(dp,-1,sizeof(dp));
        ll p=digi(b, 0, 0, 1);
        memset(dp,-1,sizeof(dp));
        ll q=digi(a,0,0,1);
        cout << p-q << endl;
    }
    return 0;
}
