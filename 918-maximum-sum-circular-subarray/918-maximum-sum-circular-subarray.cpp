class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mxElement = *max_element(nums.begin(), nums.end());
        if(mxElement <= 0)
            return mxElement;
        
        int n = nums.size(), p[30010] = {}, s[30010] = {};
        int ps = 0, ss = 0;
        
        for(int i = 1, j = n; i <= n; i++, j--){
            ps += nums[i-1];
            ss += nums[j-1];
            
            p[i] = max(p[i-1], ps);
            s[j] = max(s[j + 1], ss);
        }
        
        int ans = maxSubarraySum(nums);
        for(int i = 1; i <= n; i++){
            ans = max(ans, p[i] + s[i + 1]);
        }
        return ans;
    }
    
    int maxSubarraySum(vector<int> &nums){
        int mxSum = 0, sum = 0;
        
        for(int x: nums){
            sum += x;
            if(sum < 0)
                sum = 0;
            if(sum > mxSum)
                mxSum = sum;
        }
        return mxSum;
    }
};