class Solution {
public:
    int minDistance(string word1, string word2) {
       int n = word1.size(), m = word2.size();
        
        // space optimized lcs implementaion
        int last[501] = {};
        for(int i = 1; i <= n; i++){
            int curr[501] = {};
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    curr[j] = 1 + last[j-1];
                else
                    curr[j] = max(curr[j-1], last[j]);
            }
            copy(begin(curr), end(curr), begin(last));
        }        
        return n + m - 2*last[m];
    }
};