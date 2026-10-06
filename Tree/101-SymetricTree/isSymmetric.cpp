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
    private:
    bool fun(TreeNode* node1 , TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr) return true;
        if(node1 == nullptr || node2 == nullptr) return false;
        if(node1 -> val != node2->val) return false;
       bool r1 = fun(node1->left,node2->right);
        bool r2=fun(node1->right,node2->left);
        if(r1 == true && r2 == true) return true;
        return false;
    };
public:
    bool isSymmetric(TreeNode* root) {
       return fun(root->left,root->right);
    }
};