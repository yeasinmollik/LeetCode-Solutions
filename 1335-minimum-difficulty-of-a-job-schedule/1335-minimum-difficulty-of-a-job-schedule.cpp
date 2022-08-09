class Solution {
public:
    int inf = 1e9;
    int n;
    int dp[310][11];
    
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        if(n < d)
            return -1;
        
        memset(dp, -1, sizeof(dp));
        reverse(jd.begin(), jd.end());
        int ans = solve(0, d, jd);
        return ans >= inf? -1 : ans;
    }
    
    int solve(int start, int d, vector<int> &jd){
        // base case
        if(start == n) 
            return d == 0? 0: inf;
        
        if(d <= 0 || (n - start) < d)
            return inf;
        
        if(dp[start][d] != -1)
            return dp[start][d];
        
        int mx = jd[start];
        int minDifficulty = inf;
        
        for(int i = start; i < n; i++){
            mx = max(jd[i], mx);
            minDifficulty = min(minDifficulty, mx + solve(i + 1, d - 1, jd));
        }
        return dp[start][d] = minDifficulty;
    }
};