class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        vector<int>odd;
        vector<int>even;
        vector<int>ans;
        int n = arr.size();
        for(int i = 0 ; i < n;i++){
            if(arr[i] % 2 == 0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.begin(),even.end());
        int m = odd.size();
        for(int i = 0 ; i < odd.size();i++){
            arr[i] = odd[i];
        }
        for(int i = 0; i < even.size(); i++) {
                   arr[m + i] = even[i];
               }
        
    }
};