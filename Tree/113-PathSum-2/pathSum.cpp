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
    vector<vector<int>>res;
     private:
    void fun(TreeNode* root, int targetSum,int sum, vector<int>& diary){
  if(root == nullptr) return;
        sum = sum + root -> val;
        diary.push_back(root->val);
        if(root->right == nullptr && root->left == nullptr){
            if(sum == targetSum) {
                res.push_back(diary);
                
            }
            diary.pop_back();
                return;
        }
            fun(root->left,targetSum, sum,diary);
        fun(root->right,targetSum, sum, diary);
        diary.pop_back();
       
        }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        vector<int> diary;
        fun(root,targetSum,0,diary);
        return res;
    }
};