class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = 0, cnt = 0, ans = 0;
        while(r < n){
            cnt += nums[r];
            while(cnt < (r - l)){
                cnt -= nums[l];
                l++;
            }    
            ans = max(ans, r - l);
            r++;
        }
        return ans;
    }
};