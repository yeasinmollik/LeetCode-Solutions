class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int, int> m = {{0, 0}};
        
        for(int i = 1; i <= n; i++){
            sum += nums[i-1]? 1: -1;
            if(m.find(sum) != m.end())
                ans = max(ans, i - m[sum]);
            if(m.find(sum) == m.end())
                m[sum] = i;
        }
        return ans;
    }
};


