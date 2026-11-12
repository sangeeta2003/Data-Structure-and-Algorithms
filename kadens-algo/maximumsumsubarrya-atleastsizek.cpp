class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0;
       
        int sum = 0;
        int last = 0;
        int mx = INT_MIN;
        for(int j = 0 ; j < n ;j++){
            sum += arr[j];
            if(j - i + 1 == k){
                mx = max(sum,mx);
            }
            else if(j - i + 1 > k){
                mx = max(sum,mx);
                last += arr[i];
                i++;
                if(last < 0){
                    sum -= last;
                    last = 0;
                    mx = max(sum,mx);
                }
                
            }
        }
        return mx;
    }
};