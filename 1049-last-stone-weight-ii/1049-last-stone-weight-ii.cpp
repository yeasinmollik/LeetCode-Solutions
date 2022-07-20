class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)
            return stones[0];
        
        int tot = 0;
        for(int &x: stones)
            tot += x;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(tot + 1, false));
        
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= tot; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= stones[i-1])
                    dp[i][j] = dp[i][j] | dp[i-1][j - stones[i-1]];
            }
        }
        
        for(int i = tot/2; i >= 1; i--)
            if(dp[n][i])
                return tot - i - i;
        
        return 0;
    }
};