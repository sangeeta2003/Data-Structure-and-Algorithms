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
    TreeNode* prev = nullptr;
    bool ans = true;
    void fun(TreeNode* root){
        if(root == nullptr) return;
        fun(root->left);
        if(prev == nullptr){
            prev = root;

        }else{
            if(root->val <= prev -> val)
            ans = false;
            prev = root;
        }
        fun(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        fun(root);
        return ans;
    }
};