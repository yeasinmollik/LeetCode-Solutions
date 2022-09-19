class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128] = {};
        int n = s.size();
        
        int l = 0, r = 0, ans = 0;
        while(r < n){
            cnt[s[r]]++;
            while(hasRepeatedChars(cnt)){
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
    
    bool hasRepeatedChars(int cnt[]){
        for(int i = 0; i < 128; i++)
            if(cnt[i] > 1)
                return true;
        return false;
    }
};