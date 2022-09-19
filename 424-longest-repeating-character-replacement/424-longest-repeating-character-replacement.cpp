class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(char i = 'A'; i <= 'Z'; i++){
            int l = 0, r = 0;
            int cnt = 0;
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