class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = 0, r = 0, prod = 1, ans = 0;
        while(r < n){
            prod *= nums[r];
            while(l <= r && prod >= k){
                prod /= nums[l];
                l++;
            } 
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};