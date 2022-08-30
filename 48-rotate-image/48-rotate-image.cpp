class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++){
            int l = 0, r = n-1;
            while(l < r)
                swap(mat[i][l], mat[i][r]), l++, r--;
        }
        
        for(int i = 0, j = n-1; i < n; i++, j--){
            int i1 = 0, j1 = i;
            int i2 = j, j2 = n-1;
            
            while(i1 < i2){
                swap(mat[i1][j1], mat[i2][j2]);
                i1++, j1++, i2--, j2--;
            }
        }
        
        for(int i = 1, j = n-2; i < n; i++, j--){
            int i1 = i, j1 = 0;
            int i2 = n-1, j2 = j;
            
            while(i1 < i2){
                swap(mat[i1][j1], mat[i2][j2]);
                i1++, j1++, i2--, j2--;
            }
        }
    }
};
