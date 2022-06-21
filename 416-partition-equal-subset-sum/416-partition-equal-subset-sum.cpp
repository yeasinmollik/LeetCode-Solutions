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
        
        vector<bool> last(target + 1), curr(target + 1);
        last[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++) {
                curr[j] = last[j];
                
                if(j >= nums[i-1])
                    curr[j] = curr[j] | last[j - nums[i-1]];
            }
            last = curr;
        }
        
        return last[target];
    }
    
};