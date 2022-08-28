class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, ans = 1e9;
        
        while(r < n){
            sum += nums[r];
            while(sum >= target && l <= r){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans == 1e9? 0: ans;
    }
};