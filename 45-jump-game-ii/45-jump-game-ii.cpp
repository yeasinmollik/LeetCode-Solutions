class Solution {
public:
    int inf = 1e8;
    int dp[10010];
    
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return minJump(0, nums);
    }
    
    int minJump(int idx, vector<int> &nums){
        if(idx >= nums.size() - 1)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int mn = inf, right = idx + nums[idx];
        for(int i = idx + 1; i <= right; i++)
            mn = min(mn, 1 + minJump(i, nums));
        
        return dp[idx] = mn;
    }
};