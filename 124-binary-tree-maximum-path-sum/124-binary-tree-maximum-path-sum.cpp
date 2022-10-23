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
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        solve(root, mx);
        return mx;
    }
    
    int solve(TreeNode* root, int &mx){
        if(!root)
            return 0;
        
        int left = root->val + solve(root->left, mx);
        int right = root->val + solve(root->right, mx);
        
        mx = max({mx, root->val, left, right, left + right - root->val});
        return max({root->val, left, right});
    }
};