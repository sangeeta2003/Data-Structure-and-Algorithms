class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        int i = 0;
        int j= 0;
        int k = 0;
        vector<int>ans(n+m);
        while(i < n && j < m){
            if(a[i] < b[j] ){
               ans[k] = a[i];
               i++;
                 }else{
                     ans[k] = b[j];
                     j++;
                 }
                 k++;
                 
        }
        while(i < n){
            ans[k++] = a[i++];
        }
        while(j < m){
            ans[k++] = b[j++];
        }
        for(int i = 0 ; i < n;i++){
            a[i] = ans[i];
        }
        for(int j =0 ; j < m ;j++){
            b[j] = ans[j+n];
        }
    }
};