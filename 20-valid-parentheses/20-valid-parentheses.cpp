class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {{')', '('}, 
                                       {']', '['}, 
                                       {'}', '{'}
                                      };
        stack<char> st;
        for(char c: s){
            if(m.count(c)){
                if(st.empty() || st.top() != m[c])
                    return false;
                st.pop();
            }
            else
                st.push(c);
        }
        return st.empty();
    }
};