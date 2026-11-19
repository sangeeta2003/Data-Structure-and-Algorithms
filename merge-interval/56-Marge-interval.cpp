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