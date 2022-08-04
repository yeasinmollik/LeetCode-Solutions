class Solution {
public:
    int dp[1010][1010], pre1[1010] = {}, pre2[1010] = {};
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        
        pre1[0] = s1[0], pre2[0] = s2[0];
        for(int i = 1; i < s1.size(); i++)
            pre1[i] = pre1[i-1] + s1[i];
        for(int i = 1; i < s2.size(); i++)
            pre2[i] = pre2[i-1] + s2[i];
        
        return solve(s1, s2, s1.size() - 1, s2.size() - 1);
    }
    
    int solve(string &s1, string &s2, int i, int j){
        if(i < 0 && j < 0)
            return 0;
        
        if(i < 0)
            return pre2[j];
        
        if(j < 0)
            return pre1[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i-1, j - 1);
        else
            return dp[i][j] = min(s1[i] + solve(s1, s2, i-1, j), s2[j] + solve(s1, s2, i, j-1));
    }
};