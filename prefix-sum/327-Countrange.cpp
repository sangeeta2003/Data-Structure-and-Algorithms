class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n + 1, lower, upper);
    }

    int mergeSort(vector<long long>& prefix, int left, int right,
                  int lower, int upper) {

        if (right - left <= 1) return 0;

        int mid = left + (right - left) / 2;

        int cnt = mergeSort(prefix, left, mid, lower, upper)
                + mergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid;

        for (int i = left; i < mid; i++) {

            while (k < right && prefix[k] - prefix[i] < lower)
                k++;

            while (j < right && prefix[j] - prefix[i] <= upper)
                j++;

            cnt += j - k;
        }

        vector<long long> temp;
        int i = left, p = mid;

        while (i < mid && p < right) {
            if (prefix[i] <= prefix[p])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[p++]);
        }

        while (i < mid)
            temp.push_back(prefix[i++]);

        while (p < right)
            temp.push_back(prefix[p++]);

        for (int x = 0; x < temp.size(); x++)
            prefix[left + x] = temp[x];

        return cnt;
    }
};