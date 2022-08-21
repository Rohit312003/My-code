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
const int N=1e5+10;
vector<int> gra[N];
bool vis[10000];

void dfs(int v){

vis[v]=true;
for(int child:gra[v]){
  
if(vis[child]){continue;}
cout<<child<<" ";

dfs(child);
}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

  int a,b;
  cin>>a>>b;

  for(int i=0;i<b;i++){
    int u,m;
    cin>>u>>m;

gra[u].push_back(m);
gra[m].push_back(u);
  }
  cout<<1<<" ";
dfs(1);


   return 0;
}