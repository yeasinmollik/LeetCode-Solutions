class Solution {
public:
    int n, m;
    int x[4] = {1, 0, 0, -1}, y[4] = {0, 1, -1, 0};
    bool vis[50][50] = {};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !vis[i][j]){
                    int area = 0;
                    dfs(i, j, area, grid);
                    if(area > maxArea)
                        maxArea = area;
                }
            }
        }
        
        return maxArea;
    }
    
    void dfs(int i, int j, int &area, vector<vector<int>> &grid){
        area++;
        vis[i][j] = true;
        
        for(int k = 0; k < 4; k++){
            int p = i + x[k], q = j + y[k];
            if(p >= 0 && p < n && q >= 0 && q < m && grid[p][q] && !vis[p][q])
                dfs(p, q, area, grid);
        }
    }
};