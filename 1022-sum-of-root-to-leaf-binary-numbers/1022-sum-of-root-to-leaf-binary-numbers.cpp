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
    void dfs(TreeNode* root, int &sum ,string cur){
        if(root==nullptr){
            return;
        }
        cur+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            sum +=stoi(cur,nullptr,2);
            return;
        }
        dfs(root->left,sum,cur);
        dfs(root->right,sum,cur);
        

    }
    int sumRootToLeaf(TreeNode* root) {
        int sum =0;
        dfs(root,sum,"");
        return sum;
    }
};