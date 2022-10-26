public class Solution {
    public bool IsValid(string s) {
        int n = s.Length;
        
        Stack<char> st = new Stack<char>();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.Push(s[i]);
            else if(st.Count == 0)
                return false;
            else if(s[i] == ')'){
                if(st.Peek() != '(')
                    return false;
                else
                    st.Pop();
            }
            else if(s[i] == '}'){
                if(st.Peek() != '{')
                    return false;
                else
                    st.Pop();
            }
            else if(s[i] == ']'){
                if(st.Peek() != '[')
                    return false;
                else
                    st.Pop();
            }
        }
        
        return st.Count == 0;
    }
}