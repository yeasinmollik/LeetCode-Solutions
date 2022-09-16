class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> idx;
        
        for(int i = 0; i < n; i++){
            int toHave = target - nums[i];
            if(idx[toHave] > 0)
                return {i, idx[toHave]-1};
            idx[nums[i]] = i + 1;
        }
        return {-1, -1};
    }
};