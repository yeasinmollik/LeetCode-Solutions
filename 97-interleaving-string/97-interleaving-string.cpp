class Solution {
public:
    char dp[101][101][201][2];
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s1, s2, s3, true) | solve(0, 0, 0, s1, s2, s3, false);
    }
    
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3, bool first){
        if(k == s3.size())  //base case
            return true;
        
        if(dp[i][j][k][first] != -1)
            return dp[i][j][k][first];
        
        bool solved = false; 
        if(first){
            for(int i1 = i, k1 = k; i1 < s1.size() && !solved; i1++, k1++){
                if(s1[i1] == s3[k1])
                    solved = solve(i1 + 1, j, k1 + 1, s1, s2, s3, !first);
                else
                    break;
            }            
        }
        else{
            for(int j1 = j, k1 = k; j1 < s2.size() && !solved; j1++, k1++){
                if(s2[j1] == s3[k1])
                    solved = solve(i, j1 + 1, k1 + 1, s1, s2, s3, !first);
                else
                    break;
            }
        }
        
        return dp[i][j][k][first] = solved;
    }
};