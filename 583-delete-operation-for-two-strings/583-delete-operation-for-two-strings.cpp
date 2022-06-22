class Solution {
public:
    int minDistance(string word1, string word2) {
       int n = word1.size(), m = word2.size();
        int lcs[501][501] = {};
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }        
        return n + m - 2*lcs[n][m];
    }
};