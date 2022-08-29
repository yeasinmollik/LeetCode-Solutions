class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int m[200010];
        memset(m, -1, sizeof(m));
        int zero = 100000, sum = 0, ans = 0;
        m[zero] = 0;
        for(int i = 1; i <= n; i++){
            sum += nums[i-1]? 1: -1;
            int rightShifted = sum + zero;
            if(m[rightShifted] != -1)
                ans = max(ans, i - m[rightShifted]);
            if(m[rightShifted] == -1)
                m[rightShifted] = i;
        }
        return ans;
    }
};


