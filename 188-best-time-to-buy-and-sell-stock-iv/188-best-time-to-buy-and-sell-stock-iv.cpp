class Solution {
public:
    int dp[1010][110];
    int n;
    
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k, prices);
    }
    
    int solve(int curr, int k, vector<int>& prices){
        if(curr == n || k == 0)
            return 0;

        if(dp[curr][k] != -1)
            return dp[curr][k];

        int mx = solve(curr + 1, k, prices);
        for(int i = curr + 1; i < n; i++){
            if(prices[i] > prices[curr])
                mx = max(mx, prices[i] - prices[curr] + solve(i + 1, k-1, prices));
        }
        return dp[curr][k] = mx;
    }
};