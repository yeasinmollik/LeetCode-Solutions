class Solution {
public:
    // dp[i][j][k] = number of distinct sequences of length i, ending at j, k
    int dp[10010][7][7];
    int n;
    int mod = 1e9 + 7;
    
    int distinctSequences(int x) {
        n = x;
        memset(dp, -1, sizeof(dp));
        return dfs(1, 0, 0);
    }
    
    int dfs(int i, int prev, int pre_prev){
        // sequence of length n has been found, so return 1
        if(i == n + 1)
            return 1;
        
        if(dp[i][prev][pre_prev] != -1)
            return dp[i][prev][pre_prev];
        
        int total = 0;     
        for(int curr = 1; curr < 7; curr++){
            if(curr != prev && curr != pre_prev && (prev == 0 || __gcd(prev, curr) == 1))
                total = (total + dfs(i + 1, curr, prev)) % mod;
        }
        
        return dp[i][prev][pre_prev] = total;
    }
};