class Solution {
public:
    int dp[40010][3];
    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return getMax(nums.size() - 1, 0, nums);
    }
    
    int getMax(int idx, int mod, vector<int> &nums){
        //we must have mod=0 after at the end otherwise return INT_MIN
        if(idx == -1)
            return (mod == 0? 0 : INT_MIN);
        
        if(dp[idx][mod] != -1)
            return dp[idx][mod];
        
        return dp[idx][mod] = max(nums[idx] + getMax(idx - 1, (mod - (nums[idx] % 3) + 3) % 3, nums), getMax(idx - 1, mod, nums));
    }
};