class Solution {
public:
    int n;
    vector<vector<char>> dp;
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(int &x: nums)   
            sum += x;
        if(sum % 2 == 1)
            return false;
        int target = sum / 2;
        dp.resize(n, vector<char>(target + 1, -1));
        return canSubsetSum(nums, 0, 0, target);
    }
    
    bool canSubsetSum(vector<int>& nums, int idx, int sum, int target) {
        if(sum == target)
            return true;
        if(idx == n || sum > target)
            return false;
        if(dp[idx][sum]!= -1)
            return dp[idx][sum];
        
        return dp[idx][sum] = canSubsetSum(nums, idx + 1, sum + nums[idx], target) | canSubsetSum(nums, idx + 1, sum, target);

    }
    
};