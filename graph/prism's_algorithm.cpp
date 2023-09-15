int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code herepriority
        // min heap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        // {wt,node}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            
            if(vis[node]){
                continue;
            }
            // adding to mst
            vis[node]=1;
            sum+=wt;
            
            for(auto child:adj[node]){
                
                int childwt=child[1];
                int childname=child[0];
                
                if(!vis[childname]){
                    pq.push({childwt,childname});
                }
                
                
            }
            
        }
        
        return sum;
        
    }
