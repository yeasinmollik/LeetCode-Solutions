class Solution {
public:
    string minWindow(string s, string t) {
        int req[123] = {};
        for(char &c: t)
            req[c]++;
        
        int have[123] = {};
        int l = 0, r = 0, n = s.size();
        int minW = INT_MAX, ml = 0;
        
        while(r < n){
            have[s[r]]++;
            if(okay(have, req)){
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
    
    bool okay(int have[], int req[]){
        for(int i = 65; i < 123; i++)
            if(have[i] < req[i])
                return false;
        return true;
    }
};