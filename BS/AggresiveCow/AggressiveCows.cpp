class Solution {
    private:
    bool fun(vector<int> & arr, int k , int guess){
        int cow = 1;
        int prev = arr[0];
        for(int i = 1 ; i < arr.size();i++){
            int dist = arr[i] - prev;
            if(dist < guess) continue;
            cow++;
            prev = arr[i];
            if(cow >= k) return true;

        }
        return false;
    }
    
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int low = 1;
        int high = arr[n-1] - arr[0];
        int res = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(fun(arr,k,mid)){
                res = mid;
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        
return res;
        
    }
};