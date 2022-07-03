class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // dp[i][0] = longest wiggle subsequence at nums[i] with nums[i] < last element
        // dp[i][1] = longest wiggle subsequence at nums[i] with nums[i] > last element
        int dp[1010][2];
        dp[0][0] = dp[0][1] = 1;
        int max_len = 1;
        
        for(int j = 1; j < nums.size(); j++){
            dp[j][0] = dp[j][1] = 1;
            for(int i = 0; i < j; i++){
                if(nums[i] < nums[j])
                    dp[j][1] = max(dp[j][1], dp[i][0] + 1);
                else if(nums[i] > nums[j])
                    dp[j][0] = max(dp[j][0], dp[i][1] + 1);
            }
            max_len = max({max_len, dp[j][0], dp[j][1]});
        }
        return max_len;
    }
};