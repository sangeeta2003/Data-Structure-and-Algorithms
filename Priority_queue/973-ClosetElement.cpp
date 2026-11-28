class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq;

        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            long long dist = 1LL * x * x + 1LL * y * y;

            if(pq.size() < k) {
                pq.push({dist, i});
            }
            else if(dist < pq.top().first) {
                pq.pop();
                pq.push({dist, i});
            }
        }

        vector<vector<int>> res;

        while(!pq.empty()) {
            int idx = pq.top().second;
            res.push_back(points[idx]);
            pq.pop();
        }

        return res;
    }
};