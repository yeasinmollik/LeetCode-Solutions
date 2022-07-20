class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n), lisCnt(n);
        int mxLen = 1, ans = 0;
        
        for(int i = 0; i < n; i++){
            int cnt = 1;
            lis[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(lis[j] + 1 > lis[i]){
                        lis[i] = lis[j] + 1;
                        cnt = lisCnt[j];
                    }
                    else if(lis[j] + 1 == lis[i])
                        cnt += lisCnt[j];
                }
            }
            lisCnt[i] = cnt;
            if(mxLen < lis[i]) {
                ans = cnt;
                mxLen = lis[i];
            }
            else if(mxLen == lis[i])
                ans += cnt;
        }
        
        return ans;
    }
};