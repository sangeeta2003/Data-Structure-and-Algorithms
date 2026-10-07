/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res = 0;

private:
    void fun(TreeNode* root, int sum) {
        if (root == nullptr) return;

        sum = sum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            res += sum;
            return;
        }

        fun(root->left, sum);
        fun(root->right, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        res = 0;
        fun(root, 0);
        return res;
    }
};