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
    // vector<vector<int>>ans;
    // void traversal(TreeNode* root,int row){
    //     if(!root)return;
    //     if(row==ans.size()){
    //         ans.push_back(vector<int>());
    //     }
    //     ans[row].push_back(root->val);
    //     traversal(root->left,row+1);
    //     traversal(root->right,row+1);
    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // traversal(root,0);
        if(!root) return {};

        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int>temp;
            while(s--){
                TreeNode* a = q.front();
                q.pop();
                temp.push_back(a->val);
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};