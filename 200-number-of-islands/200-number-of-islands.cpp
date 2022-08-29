typedef vector<vector<char>> vvc;

class Solution {
public:
    int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
    int r, c;
    bool vis[310][310] = {};
    
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        int islands = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
    
    void dfs(int i, int j, vvc &grid){
        vis[i][j] = true;
        
        for(int k = 0; k < 4; k++){
            int i1 = i + x[k], j1 = j + y[k];
            
            if(valid(i1, j1) && grid[i1][j1] == '1' && !vis[i1][j1])
                dfs(i1, j1, grid);
        }
    }
    
    bool valid(int i, int j){
        return i >= 0 && i < r && j >= 0 && j < c;
    }
};