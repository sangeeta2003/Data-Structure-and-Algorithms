#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
     vector<int> spiral(vector<vector<int>>& matrix ){
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0 , left = 0 , right = n -1 , bottom = m -1 ;
        vector<int> result;

        while(top <= bottom && left <= right){
for(int i = left ; i <= right ; i++){
    result.push_back(matrix[top][i]);
}
top++;
for(int i = top ; i <= bottom; i++){
    result.push_back(matrix[i][right]);
}
right--;
if(top <= bottom){
    for(int i = right ; i >= left ; i--){
        result.push_back(matrix[bottom][i]);
    }
    bottom--;
}
if(left <= right){
    for(int i = bottom; i >= top; i--){
        result.push_back(matrix[i][left]);
    }
    left++;
}

        }
return result;
    }
   
};
    int main(){
        Solution sol;
        int n , m ;
        cout << "Enter value of n and m";
        cin >> n >> m;
        vector<vector<int>> matrix(m , vector<int>(n));
        cout << "Enter matrix elements:\n";
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ;j++){
                cin >> matrix[i][j];
            }
        }
vector<int>result = sol.spiral(matrix);
for(int x : result){
    cout << x << " ";
}
        
return 0;
    }