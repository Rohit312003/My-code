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
vector<int> a[1000];
int hight[100]; // intializes with 0
int depth[100];
void dfs(int v, int p)
{

    for (auto child : a[v])
    {

        if (child == p)
            continue;
        depth[child] = depth[v] + 1;
        dfs(child, v);
        hight[v] = max(hight[v], hight[child] + 1);
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin >> v;
    // we know that no edge in tree is equal to no vertices - 1
    for (int i = 0; i < v - 1; i++)
    {
        int y, z;
        cin >> y >> z;

        a[y].push_back(z);
        a[z].push_back(y);
     
    }

    dfs(1,0);
    for (int i = 1; i <= v; i++)
    {
        cout << i  << " hight " << hight[i] << " depth " << depth[i] << endl;
    }
    return 0;
}
