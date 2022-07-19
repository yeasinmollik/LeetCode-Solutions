class Solution {
public:
    int n;
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        if(n < k)
            return false;
        
        int tot = 0;
        for(int &x: nums)
            tot += x;
        
        if(tot % k != 0)
            return false;
     
        // starting with the large numbers contributes to few number of recursions.
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> buckets(k, 0);
        return solve(nums, buckets, k, tot / k, 0);
    }
    
    bool solve(vector<int> &nums, vector<int> &buckets, int k, int target, int idx){
        if(idx == n)
            return true;
        
        for(int i = 0; i < k; i++){
            if(buckets[i] + nums[idx] > target)
                continue;
            
            buckets[i] += nums[idx];
            
            if(solve(nums, buckets, k, target, idx + 1) == true)
                return true;
            
            buckets[i] -= nums[idx];
            if(buckets[i] == 0)
                return false;
        }
        return false;
    }
};