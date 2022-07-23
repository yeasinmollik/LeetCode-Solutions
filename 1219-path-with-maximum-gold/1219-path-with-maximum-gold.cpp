class Solution {
public:
    int x[4] = {1, 0, 0, -1}, y[4] = {0, 1, -1, 0};
    int n, m, mx = 0;
    int vis[110][110];
                 
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    memset(vis, 0, sizeof(vis));
                    vis[i][j] = true;
                    dfs(i, j, grid[i][j], grid);
                }
            }
        }
        
        return mx;
    }
    
    void dfs(int i, int j, int gold, vector<vector<int>>& grid){
        mx = max(mx, gold);
        for(int k = 0; k < 4; k++){
            int i1 = i + x[k], j1 = j + y[k];
            if(valid(i1, j1) && grid[i1][j1] && !vis[i1][j1]){
                vis[i1][j1] = true;
                dfs(i1, j1, gold + grid[i1][j1], grid);
                vis[i1][j1] = false;
            }
        }
    }
    
    bool valid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};