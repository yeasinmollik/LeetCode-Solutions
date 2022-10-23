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
    int good = 0;
    
    int goodNodes(TreeNode* root) {
        solve(root, -100000);
        return good;
    }
    
    void solve(TreeNode* root, int mx){
        if(!root)
            return;
        
        mx = max(mx, root->val);
        good += mx == root->val;
        solve(root->left, mx);
        solve(root->right, mx);
    }
};