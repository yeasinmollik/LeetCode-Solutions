typedef long long ll;

class Solution {
public:
    vector<vector<int>> dp;
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        dp.resize(n, vector<int>(m));
        
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = INT_MAX;
                mx = max(mx, nums1[i] * nums2[j]);
            }
        }
        
        ll ans = maxProduct(nums1.size() - 1, nums2.size() - 1, nums1, nums2);
        return ans == 0? (mx == 0? ans: mx) : ans;
    }
    
    int maxProduct(int i, int j, vector<int> &nums1, vector<int> &nums2){
        if(i <  0 || j < 0)
            return 0; 
        
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        return dp[i][j] = max({nums1[i] * nums2[j] + maxProduct(i-1, j-1, nums1, nums2), maxProduct(i-1, j, nums1, nums2), maxProduct(i, j - 1, nums1, nums2)});
    }
};