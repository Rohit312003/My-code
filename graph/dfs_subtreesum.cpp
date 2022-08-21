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
vector<int> q[1000];
int subtreesum[1000];
int c[1000];
// there is no need of visted array in tree
void dfs(int v,int p){

if(v%2==0){
    c[v]++;
}
subtreesum[v]+=v;
for(int child:q[v]){

// -------------
if(child==p){
    continue;
}

dfs(child,v);
// ------------
subtreesum[v]+=subtreesum[child];
c[v]+=c[child];
}



}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int a;
   cin>>a;

   for(int i=0;i<a-1;i++){
    int u,r;
    cin>>u>>r;

q[u].push_back(r);
q[r].push_back(u);
   }

   dfs(1,0);

for(int i=1;i<=a;i++){
   cout<<i<<" sum = "<<subtreesum[i]<<endl;
    cout<<i<<" no even no = "<<c[i]<<endl;
   }

   return 0;
}