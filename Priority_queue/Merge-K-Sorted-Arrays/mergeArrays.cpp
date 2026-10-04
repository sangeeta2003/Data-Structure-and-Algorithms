class Solution {
    struct Node {
        int value;
        int row;
        int col;

        Node(int v, int r, int c) {
            value = v;
            row = r;
            col = c;
        }
    };

    struct cmp {
        bool operator()(const Node& a, const Node& b) {
            return a.value > b.value;
        }
    };

public:
    vector<int> mergeArrays(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        priority_queue<Node, vector<Node>, cmp> pq;

        // Put first element of every row into min-heap
        for (int i = 0; i < n; i++) {
            pq.push(Node(mat[i][0], i, 0));
        }

        vector<int> res;

        while (!pq.empty()) {

            Node curr = pq.top();
            pq.pop();

            int value = curr.value;
            int row = curr.row;
            int col = curr.col;

            res.push_back(value);

            // Put next element from the same row
            if (col < m - 1) {
                pq.push(Node(mat[row][col + 1], row, col + 1));
            }
        }

        return res;
    }
};