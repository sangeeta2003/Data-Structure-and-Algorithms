class Solution {
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    bool valid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    void dfs(vector<vector<char>>& board,int i , int j , int n , int m){
        board[i][j] = '#';
        for(int k = 0 ; k < 4 ; k++){
            int r = i + x[k];
            int c = j + y[k];
            if(valid(r,c,n,m) && board[r][c] == 'O'){
                dfs(board,r,c,n,m);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int i,j;
        // firt row
        for(int j = 0 ;j < m ;j++ ){
            if(board[0][j] == 'O') dfs(board,0,j,n,m);
        }
        // last row
         for(int j = 0 ;j < m ;j++ ){
            if(board[n-1][j] == 'O') dfs(board,n-1,j,n,m);
        }
        // first col
         for(int i = 0 ;i < n ;i++ ){
            if(board[i][0] == 'O') dfs(board,i,0,n,m);
        }
          for(int i = 0 ;i < n ;i++ ){
            if(board[i][m-1] == 'O') dfs(board,i,m-1,n,m);
        }
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(board[i][j] == '#'){
 board[i][j] = 'O';
                }
               
                else{
                    board[i][j] = 'X';
                }
            }
        }
return;
    }
};