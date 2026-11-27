class Solution {
private:
    int fun(vector<int> &arr, long long pages) {
        int stu = 1;
        long long pagesStudent = 0;

        int n = arr.size();

        for(int i = 0; i < n; i++) {
            if(pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            }
            else {
                stu++;
                pagesStudent = arr[i];
            }
        }

        return stu;
    }

    long long findPages(vector<int> &arr, int n, int k) {
        if(n < k) return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            int studentCnt = fun(arr, mid);

            if(studentCnt > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        return (int)findPages(nums, nums.size(), k);
    }
};