class Solution {
public:
    int dp[21][21][3];
    
    bool PredictTheWinner(vector<int>& nums) {
        int total = 0;
        for(int x: nums)
            total += x;
        
        memset(dp, -1, sizeof(dp));
        int player1 = solve(0, nums.size() - 1, 1, nums);
        int player2 = total - player1;
        return  player1 >= player2;
    }
    
    int solve(int l, int r, int player, vector<int> &nums){
        if(l == r)
            return player == 1? nums[l] : 0;
        
        if(dp[l][r][player] != -1)
            return dp[l][r][player];
        
        if(player == 1)
            dp[l][r][player] = max(nums[l] + solve(l + 1, r, 2, nums), nums[r] + solve(l, r - 1, 2, nums));
        else
            dp[l][r][player] = min(solve(l +1, r, 1, nums), solve(l, r-1, 1, nums));
        
        return dp[l][r][player];
    }
};


