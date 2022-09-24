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
        if(root->left)
            solve(sum, target, root->left, p, ans);
        if(root->right)
            solve(sum, target, root->right, p, ans);
        
        if(!root->left && !root->right && sum == target)
                ans.push_back(p);       
        p.pop_back();
    }
};