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
const int INF=1e9+10;

vector<pair<int,int>> g[N];
vector<int> level(N,INF);
int bfs(int v,int n){
deque<int> a;
a.push_back(v);
level[v]=0;
while(!a.empty()){
    int cv=a.front();

    a.pop_front();

    for(auto child:g[cv]){
int childv=child.first;
int childw=child.second;
if(level[cv]+childw<level[childv]){
   level[childv]=level[cv]+childw;
   if(childw==1){
    a.push_back(childv);
   }else{
 a.push_front(childv);
   }
}





    }
}
if(level[n]!=INF)
return level[n];

return -1;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

  int n,m;
  cin>>n>>m;


  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;

    if(x==y)continue;

    g[x].push_back({y,0});
  g[y].push_back({x,1});






  }

  cout<<bfs(1,n);
   return 0;
}