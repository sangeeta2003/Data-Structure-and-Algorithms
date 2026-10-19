class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        int cnt = 0;
        for(int i = 0 ; i < n - 2; i++){
            if(i > 0 && arr[i - 1] == arr[i]) continue;
            int j= i + 1;
            int k = n - 1;
            while( j < k){
                int total_sum = arr[i] + arr[j] + arr[k];
                if(total_sum < sum ){
                    cnt += k - j;
                    j++;
                
                }
                else{
                    k--;
                }
               
            }
        }
        return cnt;
        
    }
};