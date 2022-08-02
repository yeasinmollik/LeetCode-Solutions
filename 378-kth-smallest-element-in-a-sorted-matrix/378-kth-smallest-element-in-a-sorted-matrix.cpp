class Solution {
public:
    int n, m, inf = 1e9 + 7;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size(), m = matrix[0].size();
        set<pair<int, int>> s;        
        if(n != 1)
            s.insert({1, 0});
        if(m != 1)
            s.insert({0, 1});
        int cnt = 1, ans = matrix[0][0];
        while(cnt < k){
            int mn = inf, i, j;
            for(auto &p: s){
                if(mn > matrix[p.first][p.second]){
                    mn = matrix[p.first][p.second];
                    i = p.first, j = p.second;
                }
            }
            if(mn != inf){
                ans = mn;
                s.erase({i, j});
                if(valid(i + 1, j) && s.find({i + 1, j}) == s.end())
                    s.insert({i + 1, j});
                if(valid(i, j + 1) && s.find({i, j + 1}) == s.end())
                    s.insert({i, j + 1});
            }
            cnt++;
        }
        return ans;
    }
    
    bool valid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};