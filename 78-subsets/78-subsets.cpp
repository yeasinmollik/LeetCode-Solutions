typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vi subset;
        vvi ans;
        solve(0, subset, nums, ans);
        return ans;
    }
    
    void solve(int idx, vi &subset, vi &nums, vvi &ans){
        if(idx == nums.size()){
            ans.emplace_back(subset);
            return;
        }
        
        subset.emplace_back(nums[idx]);
        solve(idx + 1, subset, nums, ans);
        subset.pop_back();
        solve(idx + 1, subset, nums, ans);
    }
};