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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        preorder(root, 0, res);
        
        for(int i = 1; i < res.size(); i+=2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
    
    void preorder(TreeNode* root, int level, vector<vector<int>> &res){
        if(!root)
            return;
        
        if(level >= res.size())
            res.resize(level + 1);
        
        res[level].emplace_back(root->val);
        
        preorder(root->left, level + 1, res);
        preorder(root->right, level + 1, res); 
    }
};