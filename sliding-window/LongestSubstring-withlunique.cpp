class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>freq;
        int low = 0;
        int maxLen = INT_MIN;
        for(int high =0 ; high < s.size();high++){
            freq[s[high]]++;
            
        
        while(freq.size() > k){
            freq[s[low]]--;
            if(freq[s[low]] == 0){
                freq.erase(s[low]);
                
            }
            low++;
        }
        if(freq.size() == k){
            int len = high - low + 1;
            maxLen = max(maxLen,len);
        }
        }
        if(maxLen == INT_MIN) return -1;
        return maxLen;
        
    }
};