class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int pf[100050] = {};
        int n = nums.size();
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
            pf[i] = pf[i-1] + nums[i-1];
            int l = 1, r = i; 
            while(l <= r){
                int m = (l + r)/2;
                int sum = pf[i] - pf[m-1];
                if(sum >= target)
                    l = m + 1, ans = min(ans, i - m + 1);
                else
                    r = m - 1;
            }
        }
        return pf[n] < target? 0: ans;
    }
};