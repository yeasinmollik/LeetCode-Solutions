class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        bool exists[91] = {};
        for(char c: s)
            exists[c] = true;
        
        int ans = 0;
        for(char i = 'A'; i <= 'Z'; i++){
            if(!exists[i])
                continue;
            int l = 0, r = 0, cnt = 0;
            while(r < n){
                cnt += s[r] == i;
                while(cnt + k < (r - l + 1)){
                    cnt -= s[l] == i;
                    l++;
                }
                ans = max(ans, r - l + 1);
                r++;
            }
        }
        return ans;
    }
};