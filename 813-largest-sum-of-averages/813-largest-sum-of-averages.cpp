class Solution {
public:
    int n;
    double dp[101][101];
    bool done[101][101] = {};
    double ninf = -1e9, eps = 1e-6;
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        return getMaxAvg(0, k, nums);
    }
    
    double getMaxAvg(int idx, int k, vector<int> &nums){
        if(idx == n)
            return k == 0? 0: ninf;
        
        if(k <= 0)
            return ninf;
        
        if(done[idx][k])
            return dp[idx][k];
        
        double sum = 0, avg = ninf;
        for(int i = idx; i < n; i++){
            sum += nums[i];
            avg = max(avg, sum / (i - idx + 1) + getMaxAvg(i + 1, k-1, nums));
        }
        
        done[idx][k] = true;
        return dp[idx][k] = avg;
    }
};