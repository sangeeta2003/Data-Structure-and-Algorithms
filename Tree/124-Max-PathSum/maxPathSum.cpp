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
    int ans = INT_MIN;
    private:
    int fun(TreeNode* root){
        if(root == nullptr) return 0;
        int left = max(0,fun(root->left));
        int right = max(0,fun(root->right));
        ans = max(ans,root->val+right+left);
        return root->val + max(right,left);
    }
public:
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};