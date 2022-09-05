class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {        
        vector<vector<int>> ans;
        solve(root, 0, ans);
        return ans;
    }
    
    void solve(Node *root, int level, vector<vector<int>> &ans){      
        if(!root)
            return;
        
        if(level >= ans.size())
            ans.push_back({root->val});
        else
            ans[level].push_back(root->val);
        
        for(auto child: root->children)
            solve(child, level + 1, ans);
    }
};