typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int inf = 1e9;
    int dp[101][21][101];
    
    int minCost(vi& houses, vvi& cost, int m, int n, int target) {
        int ans = inf;
        memset(dp, -1, sizeof(dp));
        if(houses[0])
            ans = solve(1, target - 1, houses[0], n, m, houses, cost);
        else {
            for(int i = 1; i <= n; i++){
                ans = min(ans, cost[0][i-1] +  solve(1, target - 1, i, n, m, houses, cost));
            }
        }
        return ans >= inf? -1: ans;
    }
    
    int solve(int idx, int target, int lastColor, int n, int m, vi& houses, vvi& cost){
        if(target < 0)
            return inf;
        
        if(idx  == m) {
            return target > 0? inf: 0;
        }
        
        if(dp[idx][lastColor][target] != -1)
            return dp[idx][lastColor][target];
        
        if(houses[idx] > 0)
            return solve(idx + 1, target - (houses[idx] != lastColor), houses[idx], n, m, houses, cost);
        
        int minC = inf;
        for(int i = 1; i <= n; i++)
            minC = min(minC, cost[idx][i-1] + solve(idx + 1, target - (i != lastColor), i, n, m, houses, cost));
        
        return dp[idx][lastColor][target] = minC;
    }
};