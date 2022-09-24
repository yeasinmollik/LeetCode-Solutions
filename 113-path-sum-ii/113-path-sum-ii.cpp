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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> p;
        
        solve(0, targetSum, root, p, ans);
        return ans;
    }
    
    void solve(int sum, int target, TreeNode *root, vector<int> &p, vector<vector<int>> &ans){          
        p.push_back(root->val);
        sum += root->val;
        
         if(!root->left && !root->right){
            if(sum == target)
                ans.push_back(p);
             p.pop_back();
            return;
        }
        
        if(root->left)
            solve(sum, target, root->left, p, ans);
        if(root->right)
            solve(sum, target, root->right, p, ans);
        
        p.pop_back();
    }
};