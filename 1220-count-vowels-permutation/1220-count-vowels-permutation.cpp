class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> vowels = {0, 4, 8, 14, 20};
        unordered_map<int, vector<int>> anc = {{0, {4}},
                                               {4, {0, 8}},
                                               {8, {0, 4, 14, 20}},
                                               {14, {8, 20}},
                                               {20, {0}}
                                               };
        
        vector<vector<int>> dp(n + 1, vector<int>(26));
        for(int v: vowels)
            dp[1][v] = 1;
        
        int mod = 1e9 + 7;
        for(int i  = 2; i <= n; i++){
            for(int v: vowels){
                for(int k: anc[v])
                    dp[i][v] = (dp[i][v] + dp[i-1][k]) % mod;
            }
        }
        int tot = 0;
        for(int x: dp[n])
            tot = (tot + x) % mod;
        return tot;
    }
};