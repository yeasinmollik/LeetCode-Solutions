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
    TreeNode* pruneTree(TreeNode* root) {
        return prune(root)? NULL: root;
    }
    
    bool prune(TreeNode* &root){
        if(!root)
            return true;
        
        bool pruneLeft = prune(root->left), pruneRight = prune(root->right);
        if(pruneLeft)
            root->left = NULL;
        if(pruneRight)
            root->right = NULL; 
        return (root->val == 0 && pruneLeft && pruneRight);
    }
};