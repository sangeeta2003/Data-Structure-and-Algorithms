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
    int idx  ;
    unordered_map<int,int>mp;
    private:
    TreeNode* fun(vector<int>& postorder, int low , int high){
        if(low > high) return nullptr;
        TreeNode* node = new TreeNode(postorder[idx--]);
        int pos = mp[node -> val];
        node -> right = fun(postorder,pos + 1 , high);
        node->left = fun(postorder,low,pos-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0 ; i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        idx = postorder.size()-1;
        return fun(postorder,0,inorder.size()-1);
    }
};