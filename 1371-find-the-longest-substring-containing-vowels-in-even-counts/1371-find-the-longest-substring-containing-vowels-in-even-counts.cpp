#include <bitset>

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        bool vowel[26] = {};
        vowel[0] = vowel[4] = vowel[8] = vowel[14] = vowel[20] = true;
        
        map<int, int> left_most;
        int parity = 0;
        left_most[parity] = 0;
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            if(vowel[s[i-1] - 'a'])
                parity = parity ^ (1 << (s[i-1] - 'a'));
            
            if(left_most.count(parity))
                ans = max(ans, i - left_most[parity]);
            
            if(!left_most.count(parity))
                left_most[parity] = i;
        }
        
        return ans;
    }
};