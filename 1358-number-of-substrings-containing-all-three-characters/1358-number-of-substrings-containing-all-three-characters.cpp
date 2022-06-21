class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        int l = 0, r = 0, ans = 0;
        int freq[100] = {}, cnt = 0;
        
        while(r < n){
            freq[s[r]]++;
            if(freq[s[r]] == 1)
                cnt++;
            
            while(l < r && cnt == 3) {
                if(freq[s[l]] == 1) {
                    ans += l + 1;
                    break;
                }
                freq[s[l]]--;
                l++;
            }    
            r++;
        }
        return ans;
    }
};