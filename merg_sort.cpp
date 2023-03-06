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
// in prefix sum indexing startfrom 1 based:)
int a[N];
void merge(int l, int r, int mid)
{
    int l_sz = mid - l + 1;
    int L[l_sz + 1];
    int r_sz = r - mid;
    int R[r_sz + 1];
    for (int i = 0; i < l_sz; i++)
    {
        L[i] = a[i + l];
    }

    for (int i = 0; i < r_sz; i++)
    {
        R[i] = a[mid + i + 1];
    }
    L[l_sz] = INT_MAX;
    R[r_sz] = INT_MAX;
    int l_i = 0;
    int r_i = 0;
    // merging
    for (int i = l; i <= r; i++)
    {

        if (L[l_i] <= R[r_i])
        {
            a[i] = L[l_i];
            l_i++;
        }
        else
        {
            a[i] = R[r_i];
            r_i++;
        }
    }
}

void merge_sort(int l, int r)
{
    int mid = (l + r) / 2;
    // base case
    if (l == r)
    {
        return;
    }
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, r, mid);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }

    merge_sort(0, t - 1);
    for (int i = 0; i < t; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}