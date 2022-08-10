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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        getLeaves(root1, v1);
        getLeaves(root2, v2);
        
        return v1 == v2;
    }
    
    void getLeaves(TreeNode *root, vector<int> &v){
        if(!root)
            return;
        
        if(!root->left && !root->right)
            v.emplace_back(root->val);
        
        getLeaves(root->left, v);
        getLeaves(root->right, v);
    }
};