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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        inorder(root -> left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int n =ans.size();
        int sum = 0;
        int i = 0 ; int j = ans.size()-1;
        while(i < j){
            sum = ans[i] + ans[j];
            if(sum == k) return true;
            else if(sum < k)i++;
            else j--;
        }

return false;
    }
};