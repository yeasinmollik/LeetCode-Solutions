class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();    
        int freq[3] = {};
        int l = 0, r = 0, cnt = 0, ans = 0;
        
        while(r < n){
            freq[s[r] - 'a']++;
            if(freq[s[r] - 'a'] == 1)
                cnt++;
            
            while(l < r && cnt == 3) {
                if(freq[s[l] - 'a'] == 1) {
                    ans += l + 1;
                    break;
                }
                freq[s[l] - 'a']--;
                l++;
            }    
            r++;
        }
        return ans;
    }
};