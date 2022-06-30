class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int l = 0, r = n-1, ans = 0;
        while(l < r){
            ans += nums[r] - nums[l];
            l++;
            r--;
        }
        
        return ans;
    }
};