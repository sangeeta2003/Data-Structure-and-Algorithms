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
public:
    bool isCompleteTree(TreeNode* root) {
        bool isNull = false;
        queue<TreeNode*>q;
        if(root == nullptr) return true;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t == nullptr) isNull = true;
            
            else {
                
                if (isNull) return false;

                q.push(t->left);
                q.push(t->right);
            }
        }

return true;

        
    }
};