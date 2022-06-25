class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end()))
            return true;
        
        int n = nums.size(), disturbance = 0;
        vector<bool> p(n), s(n);
        p[0] = s[n-1] = 1;
        
        for(int i = 1, j = n - 2; i < n; i++, j--){
            p[i] = p[i-1] & (nums[i] >= nums[i-1]);
            s[j] = s[j + 1] & (nums[j] <= nums[j + 1]);
        }
        
        if(s[1] || p[n - 2])
            return true;
        
        for(int i = 1; i < n - 1; i++)
            if(nums[i-1] <= nums[i + 1] && p[i-1] && s[i + 1])
                return true;
            
        return false;
    }
};