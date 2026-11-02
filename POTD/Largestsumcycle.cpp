class Solution {
  public:
    int largestSumCycle(vector<int>& edge) {

        int n = edge.size();

        vector<int> vis(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {

            if (vis[i] != 0) continue;

            vector<int> path;
            int curr = i;

            // Traverse the graph
            while (curr != -1 && vis[curr] == 0) {

                vis[curr] = 1;
                path.push_back(curr);

                curr = edge[curr];
            }

            // Cycle detected
            if (curr != -1 && vis[curr] == 1) {

                int sum = 0;
                int node = curr;

                do {
                    sum += node;
                    node = edge[node];

                } while (node != curr);

                ans = max(ans, sum);
            }

            // Mark current path as processed
            for (int node : path) {
                vis[node] = 2;
            }
        }

        return ans;
    }
};