class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) return false;
        
        vector<bool>visited(nums.size(), false);
        return backtrack(nums, visited, sum / k, 0, 0, k);
    }
    
    bool backtrack(vector<int>& nums,vector<bool> &visited, int target, int curr_sum, int i, int k) {
        if(i == nums.size())
            return false;
        
        if (k == 1) 
            return true;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
            visited[j] = false;
        }
        
        return false;
    }
};