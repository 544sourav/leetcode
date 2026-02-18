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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int i=0;
        while(cur!=nullptr || !st.empty()){

            while(cur!=nullptr){
                st.push(cur);
                cur=cur->left;
            }
            cur = st.top();
            st.pop();
            i++;
            if(i==k)return cur->val;
            cur = cur->right;
        }
        return 0;
    }
};