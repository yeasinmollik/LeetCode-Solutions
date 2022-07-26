class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        
        deque<int> dq;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front() < (i - k))
                dq.pop_front();
            
            dp[i] = max(nums[i], !dq.empty()? dp[dq.front()] + nums[i]: INT_MIN);
            
            while(!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();
            dq.push_back(i);                
        }
        return *max_element(dp.begin(), dp.end());
    }
      
};