class Solution {
public:
    int n, m;
    bool vis[51][51] = {};
    int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        int mxArea = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int area = 0;
                    dfs(i, j, area, grid);
                    mxArea = max(mxArea, area);
                }
            }
        }
        
        return mxArea;
    }
    
    void dfs(int i, int j, int &area, vector<vector<int>>& grid){
        area++;
        vis[i][j] = true;
        
        for(int k = 0; k < 4; k++){
            int i1 = i + x[k], j1 = j + y[k];
            if(valid(i1, j1) && grid[i1][j1] == 1 && !vis[i1][j1])
                dfs(i1, j1, area, grid);
        }
    }
    
    bool valid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};