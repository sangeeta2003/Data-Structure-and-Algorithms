class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        
        int ans = 0;
        for(int i = 1 ; i <= n -2 ;){
            // found peak
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                int cnt = 1;
                // check left
                int j = i;
                while(j > 0 && arr[j] > arr[j-1]){
                    j--;
                    cnt++;

                }
                // check right
                while(i < n -1 && arr[i] > arr[i+1]){
                    i++;
                    cnt++;
                }
                ans = max(ans,cnt);
                
            }
            else{
                // if no peak found
                i++; 

            }
        }
        return ans;
    }
};