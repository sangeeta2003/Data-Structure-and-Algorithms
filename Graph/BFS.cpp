class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>res;
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i = 0 ; i < adj[node].size();i++){
                int neigh = adj[node][i];
                if(vis[neigh] == false){
                    q.push(neigh);
                    vis[neigh] = true;
                    
                }
            }
        }
        return res;
    }
};