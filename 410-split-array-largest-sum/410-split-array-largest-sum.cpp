class Solution {
public:
    int n;
    int inf = 1e9 + 10;
    int dp[1010][51];
    
    int splitArray(vector<int>& nums, int m) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, m, nums);
    }
    
    int solve(int idx, int k, vector<int> &nums){
        if(idx == n)
            return k == 0? -inf:inf;
        
        if(k < 1)
            return inf;
        
        if(dp[idx][k] != -1)
            return dp[idx][k];
        
        int sum = 0, mn = inf;
        for(int i = idx; i < n; i++){
            sum += nums[i];
            int next = solve(i + 1, k - 1, nums);
            mn = min(mn, max(sum, next));
        }
        return dp[idx][k] = mn;
    }
};