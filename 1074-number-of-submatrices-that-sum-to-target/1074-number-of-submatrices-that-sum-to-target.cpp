class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rsum[101][101] = {};
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) {
                rsum[i][j] = rsum[i][j-1] + matrix[i-1][j-1];
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                unordered_map<int, int> cnt;
                cnt[0] = 1;
                int sum = 0;
                for(int k = 1; k <= n; k++){
                    sum += rsum[k][j] - rsum[k][i-1];
                    ans += cnt[sum - target];
                    cnt[sum]++;
                }
            }
        }
        return ans;
    }
};