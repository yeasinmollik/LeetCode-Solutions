class Solution {
public:
    int n, m, ans = 0;
    int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
    bool vis[110][110] = {};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !vis[i][j])
                    dfs(i, j, grid);
            }
        }
        return ans;
    }
    
    void dfs(int i, int j, vector<vector<int>> &g){
        vis[i][j] = true;
        update(i, j, g);
        
        for(int k = 0; k < 4; k++){
            int i1 = i + x[k], j1 = j + y[k];
            if(valid(i1, j1) && g[i1][j1] && !vis[i1][j1])
                dfs(i1, j1, g);
        } 
    }
    
    void update(int i, int j, vector<vector<int>> &g){
        for(int k = 0; k < 4; k++){
            int i1 = i + x[k], j1 = j + y[k];
            if((valid(i1, j1) && !g[i1][j1]) || i1 == n || i1 == -1 || j1 == m || j1 == -1) {
                ans++;
            }
        }    
    }
    
    bool valid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};