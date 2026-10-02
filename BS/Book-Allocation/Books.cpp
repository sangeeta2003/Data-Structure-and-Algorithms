class Solution {
    private:
    bool fun(vector<int> & arr, int n , int limit , int student){
        int k = 1;
        int page = 0;
        for(int i = 0 ; i < n ;i++){
            if(page + arr[i] <= limit){
                page = page + arr[i];
            }else{
                k++;
                page = arr[i];
            }
            if(k > student) return false;
        }
        return true;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k) return -1;
        int low = 0 , high = 0;
        int res = -1;
        for(int i = 0 ; i < n ;i++){
            low = max(low , arr[i]);
            high += arr[i];
        }
        while(low <= high){
            int mid = ( low + high) / 2;
            if(fun(arr,n,mid,k)){
                res = mid;
                high = mid - 1;
    }
    else{
        low = mid + 1;
    }
        }
        return res;

        
    }
};