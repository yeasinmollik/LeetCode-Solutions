class Solution {
public:
    int n;
    double ninf = -1e9, eps = 1e-9;
    map<pair<int, int>, double> dp;
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        return getMaxAvg(0, k, nums);
    }
    
    double getMaxAvg(int idx, int k, vector<int> &nums){
        if(idx == n)
            return k == 0? 0: ninf;
        
        if(k <= 0)
            return ninf;
        
        if(dp.find({idx, k}) != dp.end())
            return dp[{idx,k}];
        
        double sum = 0, avg = ninf;
        for(int i = idx; i < n; i++){
            sum += nums[i];
            avg = max(avg, sum / (i - idx + 1) + getMaxAvg(i + 1, k-1, nums));
        }
        return dp[{idx,k}] = avg;
    }
};