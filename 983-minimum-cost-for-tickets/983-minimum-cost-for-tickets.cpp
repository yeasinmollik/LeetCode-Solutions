//dp[i] = minimum cost to travel all days starting from days[i] to days[n-1]

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[365];
        dp[n - 1] = min({costs[0], costs[1], costs[2]});
        int intervals[3] = {1, 7, 30};
        
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = 1e9;
            for(int j = 0; j < 3; j++) {
                int next_idx = lower_bound(days.begin(), days.end(), days[i] + intervals[j]) - days.begin();
                int next_cost = (next_idx == n ? 0 : dp[next_idx]);
                dp[i] = min(dp[i], costs[j] + next_cost);                
            }
        } 
        return dp[0];
    }
};