class Solution {
    private:
    void fun(vector<vector<int>>& adj, int node, vector<bool> &vis,vector<int> & res){
        res.push_back(node);
        vis[node] = true;
        for(int i =0 ; i < adj[node].size();i++){
            int neigh = adj[node][i];
            if(vis[neigh] == false){
                fun(adj,neigh,vis,res);
            }
        }
        return;
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n,0);
        vector<int>res;
        fun(adj,0,vis,res);
        return res;
        
        
    }
};