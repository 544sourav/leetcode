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
    // vector<int>value;
    void traverse (TreeNode* root, int low, int high , int &ans){
        if(root==nullptr)return;
        int x = root->val;
       if(x>=low && x<=high)ans +=x;
        traverse(root->left ,low,high,ans);
        traverse(root->right,low,high,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans =0;
        traverse(root ,low,high,ans);
        return ans;
        // for(auto x:value){
        //     if(x>=low && x<=high)ans +=
        // }
    }
};