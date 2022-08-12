class Solution {
public:
    int maxPower(string s) {
        int pw = 1, mxpw = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1])
                pw++;
            else
                pw = 1;
            mxpw = max(mxpw, pw);
        }
        return mxpw;
    }
};