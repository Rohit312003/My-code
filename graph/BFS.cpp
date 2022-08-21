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
int vis[10000];
int level[10000];
vector<int> g[10000];
void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v]=1;
    while(q.size()>0){
   int c_v=q.front();
   q.pop();

   for(int child:g[c_v]){

if(!vis[child]){
    q.push(child);
    vis[child]=1;
    level[child]=level[c_v]+1;

}

   }


    }
}

int main(){

    int v;
    cin>>v;
    for(int i=0;i<v;i++){

int x,y;
cin>>x>>y;
g[x].push_back(y);
g[y].push_back(x);


    }

    bfs(1);
    for(int i=1;i<=v;i++){
        cout<<i<<" "<<level[i]<<endl;
    }
    return 0;
}