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
    int fun(TreeNode* root){
        if(root == nullptr) return 0;
        int left = fun(root -> left);
        int right = fun(root -> right);
        int sum = left + right;
        res = max(res,sum);
        return 1 + max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        fun(root);
        return res;
    }
};