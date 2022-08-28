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
    int diameter = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return diameter;
    }
        
    int solve(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int left = solve(root->left) + 1, right = solve(root->right) + 1;
        diameter = max(diameter, left + right - 2);
        return max(left, right);
    }
};