class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n + 1), s(n + 2);
        
        for(int i = 1, j = n; i <= n; i++, j--){
            p[i] = nums[i-1] == 1? p[i-1] + 1 : 0;
            s[j] = nums[j-1] == 1? s[j+1] + 1 : 0;
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, p[i-1] + s[i+1]);
        return ans;
    }
};