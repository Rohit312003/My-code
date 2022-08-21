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
vector<int> g[10000];
int vis[10000];
int level[10000];

void bfs(int v){
queue<int> q;
q.push(v);
vis[v]=1;

while(!q.empty()){
int c=q.front();
q.pop();
for(int child:g[c]){
  if(!vis[child]){

q.push(child);
level[child]=1+level[c];
vis[child]=1;

  }
}






}


}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
int n;
cin>>n;
for(int i=0;i<n;i++){

  int x,y;
  cin>>x>>y;
g[x].push_back(y);

g[y].push_back(x);

}

bfs(1);

for(int i=1;i<n+1;i++){
  cout<<i<<" "<<level[i]<<endl;
}
   return 0;
}