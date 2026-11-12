class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        int mini = nums[0];

        int ans = nums[0];

        int start = 0;
        int ansStart = 0, ansEnd = 0;

        for(int i = 1; i < n; i++) {

            if(nums[i] < 0) {
                swap(maxi, mini);
            }

            if(nums[i] > maxi * nums[i]) {
                maxi = nums[i];
                start = i;
            }
            else {
                maxi = maxi * nums[i];
            }

            mini = min(nums[i], mini * nums[i]);

            if(maxi > ans) {
                ans = maxi;
                ansStart = start;
                ansEnd = i;
            }
        }

        cout << "Maximum Product: " << ans << endl;
        cout << "Subarray: ";

        for(int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }

        return ans;
    }
};