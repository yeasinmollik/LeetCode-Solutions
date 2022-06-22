class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        
        int dp[5010] = {};
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = (prices[1] > prices[0] ? prices[1] - prices[0] : 0);
        
        for(int i = 3; i <= n; i++) {
            int mx = max(dp[i-1], (prices[i-1] > prices[0] ? prices[i-1] - prices[0] : 0));
            for(int j = 2; j < i; j++){
                mx = max(mx, prices[i-1] - prices[j-1] + dp[j - 2]);
            }
            dp[i] = mx;
            cout << dp[i] << " ";
        }
        
        return *max_element(dp, dp + 5010);
    }
};