class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[100010];
        
        deque<int> dq;
        int maxSubsetSum = INT_MIN;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front() < (i - k))
                dq.pop_front();
            
            dp[i] = max(nums[i], !dq.empty()? dp[dq.front()] + nums[i]: INT_MIN);
            if(dp[i] > maxSubsetSum)
                maxSubsetSum = dp[i];
            
            while(!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();
            dq.push_back(i);                
        }
        return maxSubsetSum;
    }
      
};