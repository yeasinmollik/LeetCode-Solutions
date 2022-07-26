class Solution {
public:
    int dp[1010][1010];
    
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return distinct(s, t, s.size()-1, t.size()-1);
    }
    
    int distinct(string &s, string &t, int i, int j){
        if(j < 0)
            return 1;
        
        if(i < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int with = s[i] == t[j]? distinct(s, t, i-1, j-1) : 0;
        int without = distinct(s, t, i-1, j);
        return dp[i][j] = with + without;
    }
};