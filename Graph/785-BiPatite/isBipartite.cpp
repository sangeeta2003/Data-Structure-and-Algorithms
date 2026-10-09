class Solution {
    int res = false;
    void dfs(vector<vector<int>>& graph,int node,int c, vector<int>& colors){
        colors[node] = c;
        for(int j = 0 ; j < graph[node].size();j++){
            int neigh = graph[node][j];
            if(colors[neigh] != -1 && colors[neigh] == c) res = true;
            if(colors[neigh] == -1){
                dfs(graph,neigh,1-c,colors);
            }
        }
        return;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,-1);
        res = false;
        for(int i = 0 ; i < n ;i++){
            if(colors[i] ==-1 ){
                dfs(graph,i,0,colors);
            }
        }
        return !res;
    }
};