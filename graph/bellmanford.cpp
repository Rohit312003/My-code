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
vector<pair<int, pair<int,int>>> g;
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
void bellmenford(int v,int size,int e){

dist[v]=0;

for(int i=1;i<size;i++){


for(int j=0;j<e;j++){

    if((dist[g[j].first]+g[j].second.second)<dist[g[j].second.first]){
       dist[g[j].second.first]= dist[g[j].first]+g[j].second.second;
    }
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

    while(t--){

int v,e;
cin>>v>>e;


for(int i=1;i<=e;i++){
int x,y,wt;
cin>>x>>y>>wt;

g.push_back({x,{y,wt}});



}

bellmenford(1,v,e);

vector<int> a(v+1,0);
for(int j=1;j<=v;j++){
a[j]=dist[j];
}
for(int j=0;j<e;j++){

    if((dist[g[j].first]+g[j].second.second)<dist[g[j].second.first]){
       dist[g[j].second.first]= dist[g[j].first]+g[j].second.second;
    }
}

for(int j=1;j<=v;j++){
if(a[j]!=dist[j]){
    cout<<"negative cycle is there"<<endl;
    break;
}
}

    }
    
    return 0;
}