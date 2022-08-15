typedef long long ll;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n + 2), ss(n + 2);
        for(int i = 1, j = n; i <= n; i++, j--) {
            ps[i] = ps[i-1] + nums[i-1];
            ss[j] = ss[j + 1] + nums[j-1];
        }

        vector<vector<int>> mxp(n + 2, vector<int>(2));
        vector<vector<int>> mxs(n + 2, vector<int>(2));
        
        for(int i = k, j = n - k + 1; i <= n; i++, j--) {
            int ppp = ps[i] - ps[i-k];
            mxp[i] = (mxp[i-1][0] < ppp? vector<int>{ppp, i - k + 1}: mxp[i-1]);
            
            int sss = ss[j] - ss[j + k];
            mxs[j] = (mxs[j + 1][0] <= sss? vector<int>{sss, j}: mxs[j + 1]);
        }
        
        ll mxSum = 0;
        vector<int> ans;
        for(int i = 2 * k; i <= n - k; i++){
            auto left = mxp[i - k], right = mxs[i + 1];
            int midSum = ps[i] - ps[i-k];
            
            if(left[0] + midSum + right[0] > mxSum){
                mxSum = left[0] + midSum + right[0];
                ans = {left[1], i - k + 1, right[1]};
            }
        }
        ans[0]--;
        ans[1]--;
        ans[2]--;
        return ans;
    }
};