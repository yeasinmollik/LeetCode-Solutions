class Solution {
public:
    int n;
    int dp[1010][110];
    
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();    
        
        memset(dp, -1, sizeof(dp));
        return solve(0, k, prices);
    }
    
    int solve(int curr, int k, vector<int> &prices){        
        if(curr == n || k < 1)
            return 0;
        
        if(dp[curr][k] != -1)
            return dp[curr][k];
        
        int mx = solve(curr + 1, k, prices);
        for(int i = curr + 1; i < n; i++){
            if(prices[i] >= prices[curr]){
                int profit = prices[i] - prices[curr] + solve(i + 1, k - 1, prices);
                if(profit > mx)
                    mx = profit;
            }
        }        
        return dp[curr][k] = mx;
    }
};