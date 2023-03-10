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
// unionfind
int parent[N];
int size[N];
int poww(int x, int y)
{
    int a = 1;
    while (y--)
    {
        a *= x;
    }
    return a;
}

// unionfind timecomplexity O(alpha(n))
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    // path commpresion
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{

    a = find(a); /*left*/
    b = find(b); /*right*/
    if (a != b)
    {

        if (size[a] < size[b])
        {
            // union by size problem here see this
            
            swap(a, b);
            parent[b] = a;
            size[a] = b;
        }
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
    }
    return 0;
}
