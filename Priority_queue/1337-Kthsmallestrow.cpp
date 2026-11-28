class Solution {
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(int i = 0; i < m; i++) {
            int cnt = 0;

            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1)
                    cnt++;
            }

            pq.push({cnt, i});
        }

        vector<int> res;

        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};