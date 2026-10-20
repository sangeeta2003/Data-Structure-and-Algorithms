
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left,
                           arr.begin() + left + k);
    }
};

// The most important thing to remember
// You are not searching for the value x itself. You are searching for the best starting index of a window of k consecutive elements.
// - If the left element is farther from x, move left rightward.
// - Otherwise, move right leftward.
// - When left == right, that index is the best window's starting index.