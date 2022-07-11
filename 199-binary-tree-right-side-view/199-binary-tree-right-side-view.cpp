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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> view;
        dfs(root, 1, view);
        return view;
    }
    
    void dfs(TreeNode *root, int level, vector<int> &view){
        if(view.size() < level)
            view.emplace_back(root->val);
        
        if(root->right)
            dfs(root->right, level + 1, view);
        if(root->left)
            dfs(root->left, level + 1, view);
    }
};