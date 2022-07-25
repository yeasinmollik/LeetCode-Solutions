class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        
        string t = "";
        for(char &c: s){
            if(c == '('){
                st.push(t);
                t = "";
            }
            else if(c == ')'){
                reverse(t.begin(), t.end());
                t = st.top() + t;
                st.pop();
            }
            else
                t.push_back(c);
        }
        return t;
    }
};