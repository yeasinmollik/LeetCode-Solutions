class Solution {
public:
    // dp[i][j] = length of the longest fibonacci-like sequence ending at index i, j. 
    int dp[1010][1010];
    unordered_map<int, int> indexOf;
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++)
            indexOf[arr[i]] = i;
        
        int ans = 2;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++)
                ans = max(ans, solve(i, j, arr));
        }
        
        return ans > 2? ans : 0;
    }
    
    int solve(int i, int j, vector<int>& arr){
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int previous = arr[j] - arr[i];
        if(indexOf.find(previous) == indexOf.end() || indexOf[previous] >= i)
            dp[i][j] = 2;
        else
            dp[i][j] = 1 + solve(indexOf[previous], i, arr);
        
        return dp[i][j];
    }
};