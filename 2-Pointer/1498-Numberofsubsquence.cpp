
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> power(n, 1);

        for (int i = 1; i < n; i++) {
            power[i] = (2LL * power[i - 1]) % MOD;
        }

        int i = 0, j = n - 1;
        long long cnt = 0;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                cnt = (cnt + power[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }

        return cnt;
    }
};
