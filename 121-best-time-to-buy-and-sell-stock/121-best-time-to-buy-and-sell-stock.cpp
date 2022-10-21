class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            maxProfit = max(maxProfit, prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }
        
        return maxProfit;
    }
};