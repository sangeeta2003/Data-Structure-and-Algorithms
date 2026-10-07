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
    bool res = false;
    private:
    void fun(TreeNode* root, int targetSum,int sum){
  if(root == nullptr) return;
        sum = sum + root -> val;
        if(root->right == nullptr && root->left == nullptr){
            if(sum == targetSum) {
                res = true;
                return;
            }
        }
        fun(root->left,targetSum,sum);
        fun(root->right,targetSum,sum);
    };
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        res = false;
       fun(root,targetSum,0);
      
       return res;
      


    }
};