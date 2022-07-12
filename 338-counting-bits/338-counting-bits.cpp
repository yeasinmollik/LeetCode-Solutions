class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        
        for(int i = 0; i <= n; i++){
            int num = i, cnt = 0;
            while(num){
                cnt += num & 1;
                num >>= 1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};