class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        
        int dp[5010] = {};
        dp[2] = (prices[1] > prices[0] ? prices[1] - prices[0] : 0);
        int max_dp_minus_price = max(-prices[0], -prices[1]);
        
        for(int i = 3; i <= n; i++) {
            dp[i] = max(dp[i-1], prices[i-1] + max_dp_minus_price);
            max_dp_minus_price = max(max_dp_minus_price, dp[i - 2] - prices[i-1]);
        }
        
        return *max_element(dp, dp + 5010);
    }
};