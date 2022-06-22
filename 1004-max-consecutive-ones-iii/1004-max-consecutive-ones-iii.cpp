class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = 0, r = 0, ans = 0;
        int cnt[2] = {};
        while(r < n){
            cnt[nums[r]]++;  
            while(l <= r && cnt[0] > k){
                cnt[nums[l]]--;
                l++;
            }
            ans = max(ans, cnt[0] + cnt[1]);
            r++;
        }
        
        return ans;
    }
};