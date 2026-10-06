class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        int leftToRight = 1;
        vector<vector<int>> res;

        if(root == nullptr)
            return res;

        q.push(root);

        while(!q.empty()) {

            int levelSize = q.size();
            vector<int> temp(levelSize);

            int first = 0;
            int last = levelSize - 1;

            while(levelSize--) {

                TreeNode* top = q.front();
                q.pop();

                if(leftToRight == 1) {
                    temp[first] = top->val;
                    first++;
                }
                else {
                    temp[last] = top->val;
                    last--;
                }

                if(top->left != nullptr) {
                    q.push(top->left);
                }

                if(top->right != nullptr) {
                    q.push(top->right);
                }
            }

            leftToRight = 1 - leftToRight;
            res.push_back(temp);
        }

        return res;
    }
};