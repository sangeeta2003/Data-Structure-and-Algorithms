class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int baskets = 2;
        int cnt =0;
        unordered_map<int,int>f;
        int left = 0;
        int maxCnt = 0;
        for(int right = 0 ; right < fruits.size();right++){
f[fruits[right]]++;
while(f.size() > 2){
    f[fruits[left]]--;
    if(f[fruits[left]] == 0){
        f.erase(fruits[left]);
    }
    left++;
}
 int len = right - left + 1;

            maxCnt = max(maxCnt, len);

        }
        return maxCnt;
    }
};