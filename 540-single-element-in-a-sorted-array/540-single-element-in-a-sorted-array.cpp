class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {    
        int l = 0, r = nums.size()/2 -1;  
        int ans = nums.back();
        while(l <= r){
            int m = (l + r)/2;
            int f = 2*m, s = 2*m + 1;     
            if(nums[f] == nums[s])
                l = m + 1;
            else
                ans = nums[f], r = m-1;
        }
        return ans;
    }
};