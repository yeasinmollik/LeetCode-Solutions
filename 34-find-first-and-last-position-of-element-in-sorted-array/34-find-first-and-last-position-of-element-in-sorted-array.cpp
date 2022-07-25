class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, left = -1, right = -1;
        
        while(l <= r){
            int m = (l + r)>>1;
            if(nums[m] >= target){
                if(nums[m] == target)
                    left = m;
                r = m - 1;
            }
            else 
                l = m + 1;
        }
        
        l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = (l + r)>>1;
            if(nums[m] <= target){
                if(nums[m] == target)
                    right = m;
                l = m + 1;
            }
            else 
                r = m - 1;
        }
        
        return {left, right};
    }
};