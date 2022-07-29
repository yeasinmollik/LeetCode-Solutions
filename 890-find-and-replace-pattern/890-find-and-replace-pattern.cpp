class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string &w: words){
            if(isPermutation(w, pattern))
                ans.push_back(w);
        }
        return ans;
    }
    
    bool isPermutation(string &s, string &p){
        int map_s[26], map_p[26];
        memset(map_s, -1, sizeof(map_s));
        memset(map_p, -1, sizeof(map_p));
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            int cs = s[i] - 'a', cp = p[i] - 'a';
            if(map_p[cp] == -1){
                if(map_s[cs] != -1)
                    return false;
                map_p[cp] = cs;
                map_s[cs] = cp;
            }
            else if(map_p[cp] != cs)
                return false;
        }
        return true;
    }
};