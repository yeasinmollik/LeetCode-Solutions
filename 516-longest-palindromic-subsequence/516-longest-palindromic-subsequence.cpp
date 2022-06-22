class Solution {
public:
    int dp[1000][1000];
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        
        return lps(0, s.size() - 1, s);
    }
    
    int lps(int l, int r, string &s){
        if(l > r)
            return 0;
        if(l == r)
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];
        
        if(s[l] == s[r])
            return dp[l][r] = 2 + lps(l + 1, r - 1, s);
        else
            return dp[l][r] = max(lps(l + 1, r, s), lps(l, r - 1, s));
    }
};