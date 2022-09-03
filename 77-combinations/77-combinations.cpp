class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        solve(1, k, n, comb, ans);
        return ans;
    }
    
    void solve(int curr, int k, int n, vector<int> &comb, vector<vector<int>> &ans){
        if(comb.size() == k){
            ans.emplace_back(comb);
            return;
        }
        
        for(int i = curr; i <= n; i++){
            comb.emplace_back(i);
            solve(i + 1, k, n, comb, ans);
            comb.pop_back();
        }
    }
};