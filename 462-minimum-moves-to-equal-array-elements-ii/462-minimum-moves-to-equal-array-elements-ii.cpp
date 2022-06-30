class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> p(n + 1), s(n + 2);
        for(int i = 1, j = n; i <= n; i++, j--){
            p[i] = p[i-1] + nums[i-1];
            s[j] = s[j + 1] + nums[j-1];
        }
        
        long ans = min(s[1] - nums[0]*long(n - 1), nums[n-1]*long(n-1)- p[n-1]);
        for(int i = 2; i < n; i++) {
            long left = long(i-1) * nums[i-1] - p[i-1];
            long right = s[i + 1] - long(n - i)*nums[i-1];
            ans = min(ans, left + right);
        }
        return ans;
    }
};