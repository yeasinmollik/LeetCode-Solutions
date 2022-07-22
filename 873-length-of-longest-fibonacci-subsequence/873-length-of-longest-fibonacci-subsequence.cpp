class Solution {
public:
    int n;
    unordered_map<int, int> idx;
    int dp[1010][1010];
    
    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        for(int i = 0; i < n; i++)
            idx[arr[i]] = i;
        
        memset(dp, -1, sizeof(dp));
        int ans = 2;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                ans = max(ans, solve(i, j, arr));
        
        return ans > 2 ? ans : 0;
    }
    
    int solve(int j, int k, vector<int>& arr){
        if(dp[j][k] != -1)
            return dp[j][k];
        
        int prev = arr[k] - arr[j];
        if(idx.find(prev) == idx.end() || idx[prev] >= j )
            return dp[j][k] = 2;
        else
            return dp[j][k] = 1 + solve(idx[prev], j, arr);
    }
};