class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(i && nums[i-1] == nums[i])
                continue;
            auto res = threeSum(nums, i + 1, (long)target - nums[i]);
            for(auto &x: res){
                x.insert(x.begin(), nums[i]);
                ans.push_back(x);
            }
        }
        return ans;
    }
    
    // simple modification of threeSum problem
    vector<vector<int>> threeSum(vector<int>& nums, int start, long tg) {
        int n = nums.size();
        
        vector<vector<int>> ans;
        for(int i = start; i < n; i++){
            if(i > start && nums[i] == nums[i-1])
                continue; 
            
            int l = i + 1, r = n - 1;
            long target = tg - nums[i];
            while(l < r) {
                long sum = (long)nums[l] + nums[r];
                if(sum == target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    while(l < r && nums[l + 1] == nums[l])
                        l++;
                    while(l < r && nums[r - 1] == nums[r])
                        r--;
                    
                    l++, r--;
                }
                else if(sum < target)
                    l++;
                else
                    r--;
            }
        }
        
        return ans;
    }
};