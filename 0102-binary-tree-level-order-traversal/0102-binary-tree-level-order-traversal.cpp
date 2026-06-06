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
    void traversal (TreeNode*root , vector<vector<int>>&ans, int level){
        if(root==nullptr)return;
        if(level==ans.size()){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        traversal(root->left ,ans,level+1);
        traversal(root->right ,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traversal(root,ans,0);
        return ans;
    }
};