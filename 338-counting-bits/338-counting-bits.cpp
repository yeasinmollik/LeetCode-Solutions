class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int num = i, cnt = 0;
            while(num){
                cnt += num & 1;
                num /= 2;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};