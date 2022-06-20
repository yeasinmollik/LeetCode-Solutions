class Solution {
public:
    int n;
    int dp[310][310];
    
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        return solve(1, n, nums);
    }
    
    int solve(int left, int right, vector<int>& nums){
        if(left > right)
            return 0;
        
        if(dp[left][right] != -1)
            return dp[left][right];
        
        int mx = 0;
        
        for(int i = left; i <= right; i++) {
            mx = max(mx, solve(left, i-1, nums) + solve(i + 1, right, nums) + nums[left-1] * nums[i] * nums[right + 1]);
        }
        
        return dp[left][right] = mx;
    }
};