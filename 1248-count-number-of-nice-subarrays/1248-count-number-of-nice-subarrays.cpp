class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum[50010] = {};
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i-1] + (nums[i-1]&1);
        
        int first[50010], last[50010];
        for(int i = 1, j = n; i <= n; i++, j--)
            first[sum[j]] = j, last[sum[i]] = i;
        
        int mx = sum[n], ans = 0;
        for(int i = 1; i <= n; i++){
            int target = sum[i-1] + k;
            if(target >= 0 && target <= mx)
                ans += last[target] - first[target] + 1;
            //cout <<  sum[i] << " " << ans << " " << target << "\n";
        }
        return ans;
    }
    
};