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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
         vector<vector<int>>res;
         if(root == nullptr) return res;
        q.push(root);
       
       
        while(!q.empty()){
            int levSize = q.size();
            vector<int>temp;
            while(levSize--){
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);
                if(top -> left != nullptr){
                    q.push(top -> left);
                }
                if(top -> right != nullptr){
                    q.push(top -> right);
                }
               
            }
             res.push_back(temp);

        }
        return res;
    }
};