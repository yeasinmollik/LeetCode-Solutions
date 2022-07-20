class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> ids[26];
        
        for(int i = 0; i < s.size(); i++) {
            ids[s[i] - 'a'].emplace_back(i);
        }
        
        int ans = 0;
        for(string &w: words){
            if(w.size() > s.size())
                continue;
            
            int curr = -1;
            bool okay = true;
            
            for(char &c: w){
                int ci = c - 'a';
                auto ub = upper_bound(ids[ci].begin(), ids[ci].end(), curr);
                if(ub == ids[ci].end()){
                    okay = false;
                    break;
                }
                curr = *ub;
            }
            ans += okay;
        }
        
        return ans;
    }
};