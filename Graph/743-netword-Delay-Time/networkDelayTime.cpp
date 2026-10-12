
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& t : times) {
            int u = t[0] - 1;
            int v = t[1] - 1;
            int wt = t[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(n, INT_MAX);

        dist[k - 1] = 0;
        pq.push({0, k - 1});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [neigh, wt] : adj[node]) {
                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int ans = 0;

        for (int d : dist) {
            if (d == INT_MAX) return -1;
            ans = max(ans, d);
        }

        return ans;
    }
};