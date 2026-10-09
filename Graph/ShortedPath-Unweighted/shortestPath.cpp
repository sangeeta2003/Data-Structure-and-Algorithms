class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>> adj(V);
        vector<int>dist(V,-1);
        queue<int>q;
        vector<bool>vis(V,0);
        
        for(int i = 0 ; i < edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == dest){
                return dist[node];
            }
           
           
            for(int j = 0 ; j < adj[node].size();j++){
               int neigh = adj[node][j];
               if(dist[neigh] == -1) {
                   dist[neigh] = dist[node] + 1;
                   q.push(neigh);
               }
               
            }
        }
        return -1;
        
    }
};
