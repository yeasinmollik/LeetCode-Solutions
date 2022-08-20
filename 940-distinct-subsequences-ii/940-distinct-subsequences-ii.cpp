class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int cnt[125] = {};
        for(char c: s){
            int tot = 1;
            for(int i = 97; i < 123; i++)
                tot = (tot + cnt[i]) % mod;
            cnt[c] = tot;
        }
        int ans = 0;
        for(int i = 97; i < 123; i++)
            ans = (ans + cnt[i])%mod;
        return ans;
    }
};