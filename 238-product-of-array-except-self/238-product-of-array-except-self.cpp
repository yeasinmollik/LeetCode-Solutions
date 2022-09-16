class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int p[100010], s[100010];
        p[0] = s[n + 1] = 1;
        
        for(int i = 1, j = n; i <= n; i++, j--){
            p[i] = p[i-1] * nums[i-1];
            s[j] = s[j + 1] * nums[j-1];
        }
        
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            ans.push_back(p[i-1] * s[i + 1]);
        }
        return ans;
    }
};