#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
vector<int> q[N];
bool vis[N];
void dfs(int v){
vis[v]=true;
	for(auto child:q[v]){
if(vis[child])continue;

		dfs(child);
	}
}
int main() {
	int v,e;
cin>>v>>e;
for(int i=0;i<e;i++){
	int a,b;
	cin>>a>>b;
	q[a].push_back(b);
	q[b].push_back(a);
}
int count=0;
for(int i=1;i<=v;i++){
	if(vis[i])continue;

	dfs(i);
	count++;
}

cout<<count<<endl;

return 0;
}