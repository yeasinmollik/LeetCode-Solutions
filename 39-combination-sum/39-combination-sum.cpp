// to make the code concise
typedef vector<int> vi;

class Solution {
public:
    int n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        
        vi combination;
        vector<vi> ans;
        getCombinations(candidates, 0, 0, target, combination, ans);
        
        return ans;
    }
    
    void getCombinations(vi &candidates, int idx, int sum, int &target, vi &comb, vector<vi> &ans){
        if(sum == target){
            ans.emplace_back(comb);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            if(sum + candidates[i] <= target) {
                sum += candidates[i];
                comb.emplace_back(candidates[i]);
                
                getCombinations(candidates, i, sum, target, comb, ans);
                
                sum -= candidates[i];
                comb.pop_back();
            }
        }
    }
};