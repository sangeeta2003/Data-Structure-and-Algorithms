class Solution {
    bool cycle = false;
    void dfs(vector<vector<int>>& adj, int node , int parent,vector<bool>& vis){
        vis[node] = true;
        for(int j =0 ; j < adj[node].size();j++){
            int neigh = adj[node][j];
            if(vis[neigh] == 1 && neigh != parent){
                cycle = true;
            }
            if(vis[neigh] == 0 ){
                dfs(adj,neigh,node,vis);
            }
        }
        return;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        cycle = false;
        vector<bool>vis(V,0);
        vector<vector<int>> adj(V);
        for(int i =0; i < edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
            
        }
        for(int i = 0 ; i < V;i++){
            if(vis[i] == 0){
                dfs(adj,i,-1,vis);
            }
        }
        return cycle;
        
    }
};