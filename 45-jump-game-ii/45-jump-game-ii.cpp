class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), inf = 1e8, dp[10010];
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            dp[i] = inf;
            int right = min(n - 1, i + nums[i]);
            for(int j = i + 1; j <= right; j++)
                dp[i] = min(dp[i], 1 + dp[j]);
        }
        return dp[0];
    }
};