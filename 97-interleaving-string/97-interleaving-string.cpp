class Solution {
public:
    char dp[101][101][201][2];
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        if(s1.empty() && s2 == s3)
            return true;
        if(s2.empty() && s1 == s3)
            return true;
        
        memset(dp, -1, sizeof(dp)); 
        return solve(s1, s2, s3, 0, 0, 0, true) || solve(s1, s2, s3, 0, 0, 0, false);
    }
    
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, bool one){
        if(k == s3.size())
            return true;
        
        if(dp[i][j][k][(int)one] != -1)
            return dp[i][j][k][(int)one];
        
        if(one){
            if(s1[i] != s3[k])
                return false;
            
            bool solved = false;
            for(int i1 = i, k1 = k; i1 < s1.size() && !solved; i1++, k1++){
                if(s1[i1] == s3[k1])
                    solved = solve(s1, s2, s3, i1 + 1, j, k1 + 1, !one);
                else
                    break;
            }
            return dp[i][j][k][(int)one] = solved;
        }
        else {
            if(s2[j] != s3[k])
                return false;
            
            bool solved = false;
            for(int j1 = j, k1 = k; j1 < s2.size() && !solved; j1++, k1++){
                if(s2[j1] == s3[k1])
                    solved = solve(s1, s2, s3, i, j1 + 1, k1 + 1, !one);
                else
                    break;
            }
            return dp[i][j][k][(int)one] = solved;
        }
    }
};