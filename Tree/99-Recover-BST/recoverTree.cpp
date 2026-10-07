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
    TreeNode* galat1First = nullptr;
    TreeNode* galat1Sec = nullptr;
    TreeNode* galat2First = nullptr;
    TreeNode* galat2Sec = nullptr;
    int galat = 0;
    void fun(TreeNode* root){
        if(root == nullptr) return;
        fun(root->left);
        if(prev == nullptr){
            prev = root;
        }
        else{
if(root->val < prev->val){
    if(galat == 0){
        galat1First = prev;
        galat1Sec = root;
        galat++;
    }else{
galat2First = prev;
galat2Sec = root;
galat++;
    }
}
prev = root;


        }
        fun(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        fun(root);
        if(galat == 1) swap(galat1First->val,galat1Sec->val);
        else{
            swap(galat1First->val,galat2Sec->val);
        }
    }
};