class Solution {
public:
    int minDistance(string word1, string word2) {
       int n = word1.size(), m = word2.size();
        // space optimized lcs implementaion
        vector<int> last(m + 1);
        for(int i = 1; i <= n; i++){
            vector<int> curr(m + 1);
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    curr[j] = 1 + last[j-1];
                else
                    curr[j] = max(curr[j-1], last[j]);
            }
            last = curr;
        }        
        return n + m - 2*last[m];
    }
};