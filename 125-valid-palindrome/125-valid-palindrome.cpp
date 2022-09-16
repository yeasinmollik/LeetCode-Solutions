class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(char c: s){
            if(isalpha(c)){
                if(isupper(c))
                    c = tolower(c);
                t.push_back(c);
            }
            else if(isdigit(c))
                t.push_back(c);
        }
        int l = 0, r = t.size() - 1;
        while(l < r){
            if(t[l] != t[r])
                return false;
            l++, r--;
        }
        return true;
    }
};