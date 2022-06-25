class Solution {
public:
    int n, mod = 1e9 + 7;
    int dp[100010];
    
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        n = s.size();
        
        return solve(0, s, k);
    }
    
    int solve(int idx, string &s, int &mx){
        if(idx == n)
            return 1;
        
        if(s[idx] == '0')
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        long total = 0, num = 0;  
        for(int i = idx; i < n; i++) {
            num = num * 10 + (s[i] - '0');
            if(num <= mx)
                total = (total + solve(i + 1, s, mx)) % mod;
            else
                break;
        }
        
        return dp[idx] = total;
    }
};