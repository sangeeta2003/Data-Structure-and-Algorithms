class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int asc = 1;
        int dsc = 1;

        // Step 1: Check ascending and descending patterns
        for (int i = 1; i < n; i++) {

            // Check ascending circular pattern
            if (nums[i] == (nums[i - 1] + 1) % n) {
                asc++;
            }

            // Check descending circular pattern
            if (nums[i - 1] == (nums[i] + 1) % n) {
                dsc++;
            }
        }

        // Step 2: If the ascending pattern matches
        if (asc == n) {
            int first = nums[0];

            if (first == 0) {
                return 0;
            }

            int option1 = n - first;
            int option2 = first + 2;

            return min(option1, option2);
        }

        // Step 3: If the descending pattern matches
        if (dsc == n) {
            int last = nums[n - 1];

            int option1 = n - last;
            int option2 = last;

            return min(option1, option2) + 1;
        }

        // Step 4: Neither pattern matches
        return -1;
    }
};