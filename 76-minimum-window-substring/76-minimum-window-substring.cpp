class Solution {
public:
    string minWindow(string s, string t) {
        int req[123] = {};
        unordered_set<char> chars;
        for(char &c: t)
            req[c]++, chars.insert(c);
        
        int have[123] = {};
        int l = 0, r = 0, n = s.size();
        int minW = INT_MAX, ml = 0;
        
        while(r < n){
            have[s[r]]++;
            if(okay(have, req, chars)){
                while(l < r) {
                    if(have[s[l]] == req[s[l]])
                        break;
                    have[s[l]]--;
                    l++;
                }
                int currW = r - l + 1;
                if(currW < minW)
                    minW = currW, ml = l; 
            }   
            r++;
        }
        
        return minW == INT_MAX? "" : s.substr(ml, minW);
    }
    
    bool okay(int have[], int req[], unordered_set<char> &chars){
        for(auto &c: chars)
            if(have[c] < req[c])
                return false;
        return true;
    }
};