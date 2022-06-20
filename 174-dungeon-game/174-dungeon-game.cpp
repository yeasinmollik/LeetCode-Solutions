class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        
        // hp[i][j] = minimum initial health needed if we start from dungeon[i][j]
        int hp[200][200];
        
        // We move from the bottom-right to the top-left. Because, moving from the top-left to bottom-right won't give use correct answer.
        // This is because the path to be taken depends upon the future demons seen on the way to princess, which is not available in top down approach.
        
        // base case
        hp[n-1][m-1] = (dungeon[n-1][m-1] >= 0 ? 1 : -dungeon[n-1][m-1] + 1);
        
        // last row
        for(int i = m-2; i >= 0; i--) {
            int needed = hp[n-1][i + 1] - dungeon[n-1][i];
            hp[n-1][i] = (needed <= 0? 1 : needed);
        }
        
        // last column
        for(int i = n-2; i>=0; i--){
            int needed = hp[i + 1][m-1] - dungeon[i][m-1];
            hp[i][m-1] = (needed <= 0? 1: needed);
        }
            
        for(int i = n-2; i >= 0; i--) {
            for(int j = m-2; j >= 0; j--){
                int needed = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = (needed <= 0? 1 : needed);
            }
        }
            
        return hp[0][0];
    }
};