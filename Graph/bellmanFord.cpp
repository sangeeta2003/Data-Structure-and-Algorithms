
class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> res(V, 1e8);
        res[src] = 0;

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto& edge : edges) {
                int s = edge[0];
                int d = edge[1];
                int wt = edge[2];

                if (res[s] != 1e8 && res[s] + wt < res[d]) {
                    res[d] = res[s] + wt;
                }
            }
        }

        // Check for a negative-weight cycle
        for (auto& edge : edges) {
            int s = edge[0];
            int d = edge[1];
            int wt = edge[2];

            if (res[s] != 1e8 && res[s] + wt < res[d]) {
                return {-1};
            }
        }

        return res;
    }
};