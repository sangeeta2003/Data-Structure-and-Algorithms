class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);

        for (int i = 0; i < edges.size(); i++) {
            int s = edges[i][0];
            int d = edges[i][1];
            int w = edges[i][2];

            adj[s].push_back({d, w});
            adj[d].push_back({s, w});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> vis(V, 0);
        int sum = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (vis[node] == 1) continue;

            vis[node] = 1;
            sum += wt;

            for (int j = 0; j < adj[node].size(); j++) {
                int neigh = adj[node][j].first;
                int w = adj[node][j].second;

                if (vis[neigh] == 0) {
                    pq.push({w, neigh});
                }
            }
        }

        return sum;
    }
};