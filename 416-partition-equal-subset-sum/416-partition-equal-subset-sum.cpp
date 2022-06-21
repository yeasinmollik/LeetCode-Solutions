class Solution {
public:
    int n;
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(int &x: nums)   
            sum += x;
        if(sum % 2 == 1)
            return false;
        
        int target = sum / 2;   
        bool last[10010] = {}, curr[10010] = {};
        last[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++) {
                curr[j] = last[j];      
                if(j >= nums[i-1])
                    curr[j] = curr[j] | last[j - nums[i-1]];
            }
            copy(begin(curr), end(curr), begin(last));
        }
        
        return last[target];
    } 
};