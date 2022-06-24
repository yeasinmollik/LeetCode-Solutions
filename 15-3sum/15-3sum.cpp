class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(i && nums[i] == nums[i-1])
                continue; 
            
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            
            while(l < r) {
                int sum = nums[l] + nums[r];
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