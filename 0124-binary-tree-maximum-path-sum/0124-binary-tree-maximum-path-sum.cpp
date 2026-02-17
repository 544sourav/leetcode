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
    int maxsum(TreeNode* root, int &sum) {
        if (root == nullptr) return 0;

       
        int leftsum = max(0, maxsum(root->left, sum));
        int rightsum = max(0, maxsum(root->right, sum)); 
        sum = max(sum, leftsum + rightsum + root->val);

        return max(leftsum, rightsum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxsum(root, sum);
        return sum;
    }
};