class Solution {
    private:
    long long totalCnt(vector<int>& piles, int speed){
        long long cnt = 0;
        for(int i = 0 ; i < piles.size();i++){
            cnt = cnt + piles[i] / speed;
            if(piles[i] % speed != 0) cnt++;

        }
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int res = -1;

        while(low <= high){
            int mid = (low + high) / 2;
        long long hr = totalCnt(piles,mid);
        if(hr > h) low = mid + 1;
        else{
            res = mid;
            high = mid -1;
        }
        }
        return res;
    }
};