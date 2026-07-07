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
    vector<int>val;
    void traverse(TreeNode* root){
        if(root==nullptr)return;
        traverse(root->left);
        val.push_back(root->val);
        traverse(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        TreeNode* dummy = new TreeNode(0);
        TreeNode* temp =dummy; 
        for(auto x:val){
            TreeNode* t = new TreeNode(x);
            temp->right = t;
            temp = temp->right;
        }
        return dummy->right;
       
    }
};