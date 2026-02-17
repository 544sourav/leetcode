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
    void dfs(TreeNode *root, int level, vector<int> &ans) {
        if (!root) return;

       
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        dfs(root->right, level + 1, ans);
        dfs(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return{};
        vector<int> ans;
        // dfs(root, 0, ans);
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            if(ans.size()==y){
                ans.push_back(x->val);
            }
            if(x->right)q.push({x->right,y+1});
            if(x->left)q.push({x->left,y+1});
        }
        return ans;
    }
};