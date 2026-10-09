class Solution {
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    private:
    bool valid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m ) return false;
        return true;

    }
    void dfs(vector<vector<char>>& grid, int n , int m , int i , int j,vector<vector<bool>>& vis){
        vis[i][j] = 1;
        for(int k = 0 ; k < 4;k++){
            int row = i + x[k];
            int col = j + y[k];
        
        if(valid(row,col,n,m) && grid[row][col] == '1' && vis[row][col] == 0){
 dfs(grid,n,m,row,col,vis);
        }
        }
       
        return;


    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res =0;
        int i,j;
        // 2-d matrix for all array false
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        // vector<vector<bool>> vis(n);
        // for(int i =0;i<n;i++){
        //     vector<bool>t(m,0);
        //     vis[i] = t;
        // } or else you can write 2-d matrix like this 
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid,n,m,i,j,vis);
res++;
                }
            }
        }
return res;
    }
};