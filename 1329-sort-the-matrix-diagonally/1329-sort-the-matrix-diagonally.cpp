class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                mp[j - i].emplace_back(mat[i][j]);
        }
        
        for(auto &x: mp)
            sort(x.second.begin(), x.second.end(), greater<int>());
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[i][j] = mp[j - i].back();
                mp[j - i].pop_back();
            }
        }
        
        return mat;
    }
};