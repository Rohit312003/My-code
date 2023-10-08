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
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<int> vis(N, 0);
int mdd=1e9+7;
vector<int> dist(N, INF);
 vector<pair<int, int>> g[N];
int poww(int a, int y){if (y == 0){return 1;}long long x = poww(a, y / 2);if (y % 2 == 0){return (x * x) % MOD;}else{ return (a * (x * x)) % MOD;}}
//in prefix sum indexing startfrom 1 based:) 
void build(vector<int>& num,vector<int> &segtree,int ind,int l,int h){

if(l==h){
    segtree[ind]=num[l];
    return ;
}


build(num,segtree,ind*2+1,l,(l+h)/2);
build(num,segtree,ind*2+2,((l+h)/2)+1,h);

segtree[ind]=max(segtree[ind*2+1],segtree[ind*2+2]);


}

int solve(vector<int> &segtree,int l,int h,int low,int high,int  ind ){

if(l<=low&&h>=high){
    return segtree[ind];
}

if(h<low){
    return INT_MIN;
}
if(high<l){
    return INT_MIN;
}


return max(solve(segtree,l,h,low,(high+low)/2,2*ind+1),solve(segtree,l,h,((high+low)/2)+1,high,2*ind+2));

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   ll t;
   cin>>t;
   while(t--)
   {
      ll n,q;
      cin>>n>>q;
      vector<int> num(n);
      vector<int> segtree(n*5,500);
      for(int i=0;i<n;i++){
        cin>>num[i];
      }
      build(num,segtree,0,0,n-1);
    
      for(int i=0;i<q;i++){
        int l,h;
        cin>>l>>h;

        cout<<solve(segtree,l,h,0,n-1,0)<<endl;;
        
      }
   }
   return 0;
}
