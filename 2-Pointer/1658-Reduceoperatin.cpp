
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int left = 0;
        int sum = 0;
        int longest = -1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        return longest == -1 ? -1 : nums.size() - longest;
    }
};
