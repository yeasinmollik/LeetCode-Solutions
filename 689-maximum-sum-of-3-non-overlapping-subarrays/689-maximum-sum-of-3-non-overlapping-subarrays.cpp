#define mp make_pair
typedef long long ll;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ps[20010] = {}, ss[20010] = {};
        for(int i = 1, j = n; i <= n; i++, j--) {
            ps[i] = ps[i-1] + nums[i-1];
            ss[j] = ss[j + 1] + nums[j-1];
        }

        pair<int, int> mxp[20010];
        pair<int, int> mxs[20010];
        
        for(int i = k, j = n - k + 1; i <= n; i++, j--) {
            int ppp = ps[i] - ps[i-k];
            mxp[i] = (mxp[i-1].first < ppp? mp(ppp, i-k+1): mxp[i-1]);
            
            int sss = ss[j] - ss[j + k];
            mxs[j] = (mxs[j + 1].first <= sss? mp(sss, j): mxs[j + 1]);
        }
        
        ll mxSum = 0;
        vector<int> ans;
        for(int i = 2 * k; i <= n - k; i++){
            auto left = mxp[i - k], right = mxs[i + 1];
            int midSum = ps[i] - ps[i-k];
            
            if(left.first + midSum + right.first > mxSum){
                mxSum = left.first + midSum + right.first;
                ans = {left.second, i - k + 1, right.second};
            }
        }
        ans[0]--;
        ans[1]--;
        ans[2]--;
        return ans;
    }
};