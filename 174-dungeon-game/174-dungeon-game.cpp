typedef tuple<int, int, int> tupl;

class Solution {
public:
    int n, m;
    bool possible(vector<vector<int>>& dungeon, int initial_health) {
        priority_queue<tupl> pq;
        pq.push(make_tuple(initial_health + dungeon[0][0], 0, 0));
        vector<vector<int>> mx(n, vector<int>(m));
        
        while(!pq.empty()) {
            auto [health, i, j] = pq.top();
            pq.pop();
            
            if(i == n - 1 && j == m - 1)
                return true;
            
            if(i + 1 < n && dungeon[i + 1][j] + health > mx[i + 1][j]) {
                pq.push(make_tuple(health + dungeon[i + 1][j], i + 1, j));
                mx[i + 1][j] = dungeon[i + 1][j] + health;
            }
            
            if(j + 1 < m && dungeon[i][j + 1] + health > mx[i][j + 1]) {
                pq.push(make_tuple(health + dungeon[i][j + 1], i, j + 1));
                mx[i][j + 1] = dungeon[i][j + 1] + health;
            }
        }
        
        return false;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(), m = dungeon[0].size();
    
        int l = (dungeon[0][0] > 0 ? 1 : -dungeon[0][0] + 1), r = 500000, ans = 500000;
        
        while(l <= r) {
            int m = (l + r) / 2;
            
            if(possible(dungeon, m))
                r = m-1, ans = m;
            else
                l = m + 1;
        }
              
        return ans;
    }
};