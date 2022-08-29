typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vvi ans;
        vi subset;
        sort(nums.begin(), nums.end());
        solve(0, subset, ans, nums, false);
        return ans;
    }
    
    
    void solve(int idx, vi &subset, vvi &ans, vi &nums, bool pre){
        if(idx == n){
            ans.push_back(subset);
            return;
        }
        
        solve(idx + 1, subset, ans, nums, false);
        if(idx >= 1 && nums[idx-1] == nums[idx] && pre==false)
            return;
        subset.emplace_back(nums[idx]);
        solve(idx + 1, subset, ans, nums, true);
        subset.pop_back();
    }
    
};