// main idea is putting numbers into k buckets 

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
     
        // starting with the larger numbers contributes to few number of recursions.
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> buckets(k, 0);
        return put(nums, buckets, k, tot / k, 0);
    }
    
    bool put(vector<int> &nums, vector<int> &buckets, int k, int target, int idx){
        // successfully put all n numbers into k buckets
        if(idx == n)
            return true;
        
        for(int i = 0; i < k; i++){
            if(buckets[i] + nums[idx] > target)
                continue;
            
            buckets[i] += nums[idx];
            if(put(nums, buckets, k, target, idx + 1) == true)
                return true; 
            buckets[i] -= nums[idx];
            
            // no need to try other empty bucket
            if(buckets[i] == 0) 
                return false;
        }
        return false;
    }
};