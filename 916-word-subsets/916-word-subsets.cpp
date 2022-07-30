class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int cnt_b[26] = {};
        for(string &w: words2){
            int c[26] = {};
            for(char ch: w)
                c[ch - 'a']++;
            for(int i = 0; i < 26; i++)
                cnt_b[i] = max(cnt_b[i], c[i]);
        }
        
        vector<string> ans;
        for(string &w: words1){
            int c[26] = {};
            for(char ch: w)
                c[ch - 'a']++;
            bool ok = true;
            for(int i = 0; i < 26; i++){
                if(c[i] < cnt_b[i]){
                    ok = false;
                    break;
                }
            }
            if(ok)
                ans.push_back(w);
        }
        
        return ans;
    }
};