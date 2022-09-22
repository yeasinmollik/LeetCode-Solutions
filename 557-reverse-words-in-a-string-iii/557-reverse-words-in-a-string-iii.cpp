class Solution {
public:
    string reverseWords(string s) {
        s += ' ';
        string t, ans;
        for(char c: s){
            if(c == ' '){
                reverse(t.begin(), t.end());
                ans += (ans.empty()? "" : " ") +  t;
                t = "";
            }
            else
                t.push_back(c);
        }
        return ans;
    }
};