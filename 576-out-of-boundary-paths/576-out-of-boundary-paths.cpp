class Solution {
public:
    int row, col, mod = 1e9 + 7;
    int dp[51][51][51];
    int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        row = m, col = n;
        memset(dp, -1, sizeof(dp));
        
        return solve(startRow, startColumn, maxMove);
    }
    
    int solve(int i, int j, int moves){
        if(invalid(i, j))
            return 1;
        
        if(moves == 0)
            return 0;
        
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        
        int paths = 0;
        for(int k = 0; k < 4; k++)
            paths = (paths + solve(i + x[k], j + y[k], moves - 1)) % mod;
        
        return dp[i][j][moves] = paths;
    }
    
    bool invalid(int i, int j){
        return i < 0 || j < 0 || i >= row || j >= col;
    }
};