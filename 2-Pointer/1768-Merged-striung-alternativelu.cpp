class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int n = word1.size();
        int m = word2.size();
        int i =0 , j = 0;
        while(i < n && j < m){
            if(i <= j){
                merged.push_back(word1[i]);
                i++;
            }else{
                merged.push_back(word2[j]);
                j++;
            }
        }
        while(i < n) {
            merged.push_back(word1[i]);
            i++;
        }
        while(j < m) 
        {
            merged.push_back(word2[j]);
            j++;
        }
        return merged;
    }
};