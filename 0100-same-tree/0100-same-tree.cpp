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
    void check(TreeNode* root, vector<float>& v){
        if(root==NULL) {
           v.push_back(0.1);
            return;
        };
        v.push_back(root->val);
        check(root->left,v);
        check(root->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<float> v1;
        vector<float> v2;
        check(p,v1);
        check(q,v2);
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;

    }
};