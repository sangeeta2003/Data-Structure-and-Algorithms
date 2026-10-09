class Solution {
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        queue<int>q;
        vector<int>res;
        vector<int> indegree(V,0);
        for(int i = 0 ; i < edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        for(int i = 0 ; i <V ;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int j = 0 ; j < adj[node].size();j++){
                int neigh = adj[node][j];
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
                
                
            }
        }
        return res;
        
    }
};