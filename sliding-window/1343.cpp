class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
        
        int n = arr.size();
        int sum = 0;
        for(int i =0 ; i < k;i++){
sum += arr[i];

        }
        if(sum >= threshold * k ) cnt++;
for(int right = k ; right < n ;right++){
    sum += arr[right];
    sum -= arr[right - k];
     if(sum >= threshold * k ) cnt++;
    
}
return cnt;
    }
};