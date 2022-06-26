class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> idx_of_first_mod;
        
        int sum = 0;
        for(int i = 1; i <= nums.size(); i++){
            sum = (sum + nums[i-1])%k;
            
            if(sum == 0 && i > 1)
               return true;
            
            if(idx_of_first_mod[sum] && (i - idx_of_first_mod[sum]) > 1)
                return true;
            
            if(!idx_of_first_mod[sum])
                idx_of_first_mod[sum] = i;
        }       
        return false;
    }
};