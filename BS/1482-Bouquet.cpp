class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int consecutive = 0;
        int bouquet = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                consecutive++;

                if (consecutive == k) {
                    bouquet++;
                    consecutive = 0;
                }
            } 
            else {
                consecutive = 0;
            }
        }

        return bouquet >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * k > n) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                answer = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return answer;
    }
};