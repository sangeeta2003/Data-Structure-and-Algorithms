class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < n; i++) {

            int s = intervals[i][0];
            int e = intervals[i][1];

            if(s <= end) {
                // Overlapping intervals
                end = max(end, e);
            }
            else {
                // No overlap
                res.push_back({start, end});

                start = s;
                end = e;
            }
        }

        // Push the last interval
        res.push_back({start, end});

        return res;
    }
};
// Case	Changed elements	Remaining range
// 1	Two smallest	nums[n-1] - nums[2]
// 2	One smallest + one largest	nums[n-2] - nums[1]
// 3	Two largest	nums[n-3] - nums[0]