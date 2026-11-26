
class Solution {
private:
    bool possible(vector<int>& weights, int capacity, int days) {
        int requiredDays = 1;
        int currentWeight = 0;

        for (int weight : weights) {
            if (currentWeight + weight <= capacity) {
                currentWeight += weight;
            } 
            else {
                requiredDays++;
                currentWeight = weight;
            }
        }

        return requiredDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
