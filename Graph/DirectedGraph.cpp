class Solution {
    bool cycle = false;
    void dfs(vector<vector<int>>& adj, int node , vector<bool>& path,vector<bool>& vis){
           vis[node] = true;
           path[node] = true;
           for(int j =0 ; j < adj[node].size();j++){
               int neigh = adj[node][j];
               if(vis[neigh] == 1 && path[neigh] == 1){
                   cycle = true;
                   return;
               }
               if(vis[neigh] == 0 ){
                   dfs(adj,neigh,path,vis);
               }
               
           }
           path[node] = 0;
           return;
       }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        cycle = false;
               vector<bool>vis(V,0);
               vector<bool>path(V,0);
               vector<vector<int>> adj(V);
               for(int i =0; i < edges.size();i++){
                   int src = edges[i][0];
                   int dest = edges[i][1];
                   adj[src].push_back(dest);
                   

               }
               for(int i = 0 ; i < V;i++){
                           if(vis[i] == 0){
                               dfs(adj,i,path,vis);
                           }
                       }
                       return cycle;
    }
};