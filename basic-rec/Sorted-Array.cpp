class Solution {
public:
    bool check(vector<int>& arr, int i) {
        
        // Reached the last element
        if (i == arr.size() - 1)
            return true;
        
        // Current element is greater than next
        if (arr[i] > arr[i + 1])
            return false;
        
        // Check the remaining array
        return check(arr, i + 1);
    }

    bool isSorted(vector<int>& arr) {
        return check(arr, 0);
    }
};