#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    void setZeros(vector<vector<int>>& matrix ){
        int m = matrix.size();
        int n = matrix[0].size();
bool fisrRowZero = false;
bool firstColZsero = false;
        // first row have zero value
        for(int j = 0 ; j < n ; j++){
if(matrix[0][j] == 0){
    fisrRowZero = true;
    break;
}
        }
        // first col have zero value
        for(int i = 0 ; i < m ;i++){
            if(matrix[i][0] == 0){
                firstColZsero = true;
                break;
            }
        }

        // Mark rows and columns in first row/column
        for(int i = 1 ; i < m ;i++){
            for(int j = 1; j < n ;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1 ; i < m ;i++){
            for(int j = 1; j < n ;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0 ){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstColZsero){
            for(int i = 0 ; i < m ; i++){
                matrix[i][0] = 0;
            }
        }
         if(fisrRowZero){
            for(int j = 0 ; j < n ; j++){
                matrix[0][j] = 0;
            }
        }
        

    }


};
int main(){
Solution sol;

int m , n;
 cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>>matrix(m , vector<int>(n));
     cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    sol.setZeros(matrix);

    cout << "Matrix after setting zeros:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}