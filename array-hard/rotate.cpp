#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    void setZeros(vector<vector<int>>& matrix ){
        int n = matrix.size();
        for(int i =0 ;i < n ;i++){
            for(int j = i + 1 ; j < n ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0 ; i < n ;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};
int main(){

    Solution sol;
    int n ;
    cout << "Enter value of n";
    cin >> n;
    vector<vector<int>>matrix(n ,vector<int>(n) );
    cout << "Enter matrix elemeents";
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ;j++){
            cin >> matrix[i][j];
        }
    }
    sol.setZeros(matrix);
    cout << "Rotate mtraix is";
    for(int i =0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++){
            cout <<matrix[i][j]<< " ";
        }
    }
    return 0;
}