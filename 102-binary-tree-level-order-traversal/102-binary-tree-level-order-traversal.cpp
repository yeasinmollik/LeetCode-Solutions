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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root)
            dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int level, vector<vector<int>> &ans){
        if(level >= ans.size())
            ans.push_back({});
        
        ans[level].emplace_back(root->val);
        if(root->left)
            dfs(root->left, level + 1, ans);
        if(root->right)
            dfs(root->right, level + 1, ans);
    }
};