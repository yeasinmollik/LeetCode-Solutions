class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};
        
        int n = s.size(), m = p.size();
        int cp[26] = {};
        
        for(char &c: p)
            cp[c -'a']++;
        
        int cs[26] = {};
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            cs[s[i] - 'a']++;
            if(same(cs, cp))
                ans.emplace_back(i - m + 1);
            if(i >= m-1)
                cs[s[i - m + 1] - 'a']--;
        }
        return ans;
    }
    
    bool same(int a[], int b[]){
        for(int i = 0; i < 26; i++)
            if(a[i] != b[i])
                return false;
        return true;
    }
};