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
vector<int> g[N];
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
vector<int> depn(N,0);
void dfs(int v,stack<int> &s){

vis[v]=1;

for(auto child:g[v]){

if(!vis[child]){
    vis[child]=1;
 dfs(child,s);



}

}

 s.push(v);


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
        int e,v;
        cin >>v>> e;
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            
            g[x].push_back(y);
            depn[y]++;
        }

        stack<int> s;


// for(int i=1;i<=v;i++){
// if(!vis[i]){

//     dfs(i,s);
// }
// }

    //   while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    //   }
cout<<endl;
  for(int i=1;i<=v;i++){
     cout<<depn[i]<<" ";
      }

queue<int> q;

vector<int> job(N,0);

for(int i=1;i<=v;i++){
if(depn[i]==0){
    q.push(i);
    job[i]=1;
}

}


while(!q.empty()){

int cur=q.front();
q.pop();


for(auto child:g[cur]){

    depn[child]--;

    if(depn[child]==0){
        q.push(child);
        job[child]=job[cur]+1;
    }
}



}
cout<<"\n";
for(int i=1;i<=v;i++){

    cout<<job[i]<<" ";
}
    
    return 0;
}
