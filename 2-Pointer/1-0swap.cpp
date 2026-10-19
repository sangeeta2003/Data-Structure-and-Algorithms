class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            if (arr[left] == 0) {
                left++;
            }
            else if (arr[right] == 1) {
                right--;
            }
            else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};