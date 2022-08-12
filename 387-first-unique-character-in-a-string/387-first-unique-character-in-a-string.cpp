class Solution {
public:
    int firstUniqChar(string s) {
        int first[26] = {}, last[26] = {};
        for(int i = 1, j = s.size(); i <= s.size(); i++, j--){
            last[s[i-1] - 'a'] = i;
            first[s[j -1] - 'a'] = j;
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < 26; i++)
            if(first[i] && first[i]==last[i])
                ans = min(ans, first[i]);
        
        return ans == INT_MAX? -1 : ans-1;
    }
};