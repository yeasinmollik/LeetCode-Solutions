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
    long prev = LONG_MIN;
    bool valid = true;
    
    bool isValidBST(TreeNode* root) {
        check(root);
        return valid;
    }
    
    void check(TreeNode* root){
        if(!root)
            return;
        
        check(root->left);
        
        if(prev >= root->val)
            valid = false;
        
        prev = root->val;
        
        check(root->right);
    }
};