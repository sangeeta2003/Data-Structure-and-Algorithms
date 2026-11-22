class Solution {
    private:
     bool fun(unordered_map<char,int>freq1,unordered_map<char,int>freq2){
        for(auto i : freq1){
            char c = i.first;
            int need = i.second;
            int fhave = freq2[c];
            if(fhave < need) return false;
            

        }
        return true;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(int i = 0 ; i < ransomNote.size();i++){
            freq1[ransomNote[i]]++;
        }
        for(int i = 0 ; i < magazine.size();i++){
            freq2[magazine[i]]++;
        }
        return fun(freq1,freq2);
    }
};