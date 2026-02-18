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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)return new TreeNode(val);
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(node->left==nullptr && node->val>val){
                node->left = new TreeNode(val);
                break;
            }
            else if(node->right ==nullptr && node->val<val){
                node->right = new TreeNode(val);
                break;
            }
            if(node->val>val){
                st.push(node->left);
            }
            else st.push(node->right);
        }
        return root;
    }
};