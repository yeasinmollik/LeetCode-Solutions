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
    map<int, vector<pair<int, int>>> vcol;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        vector<vector<int>> ans;
        for(auto &col: vcol){
            sort(col.second.begin(), col.second.end());
            vector<int> v;
            for(auto &x: col.second)
                v.emplace_back(x.second);
            ans.emplace_back(v);
        }        
        return ans;
    }
    
    void solve(TreeNode* root, int col, int row){
        if(!root)
            return;
        
        vcol[col].emplace_back(row, root->val);
        solve(root->left, col - 1, row + 1);
        solve(root->right, col + 1, row + 1);
    }
};