class Solution {
public:

    vector<int> parent, sz;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    long long unite(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v)
            return 0;

        long long paths = 1LL * sz[u] * sz[v];

        if(sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return paths;
    }

    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        // Store queries with their original indices
        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        // Initialize DSU
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        vector<int> ans(queries.size(), 0);

        int j = 0;
        long long totalPaths = 0;

        // Process queries in increasing order
        for(auto &query : q) {

            int limit = query.first;
            int index = query.second;

            // Include all edges with weight <= limit
            while(j < edges.size() && edges[j][2] <= limit) {

                totalPaths += unite(edges[j][0], edges[j][1]);

                j++;
            }

            ans[index] = totalPaths;
        }

        return ans;
    }
};