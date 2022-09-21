class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(string s: tokens){
            if(isalnum(s.back()))
                st.push(stoi(s));
            else{
                char c = s[0];
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                if(c == '+')
                    st.push(a + b);
                else if(c == '-')
                    st.push(b - a);
                else if(c == '*')
                    st.push(a*b);
                else
                    st.push(b/a);
            }
        }
        return st.top();
    }
};