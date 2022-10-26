public class Solution {
    public bool BackspaceCompare(string s, string t) {
        return Backspaced(s) == Backspaced(t);
    }
    
    public string Backspaced(string s){
        int n = s.Length;
        Stack<char> st = new Stack<char>();
        foreach(char c in s){
            if(c == '#'){
                if(st.Count > 0)
                    st.Pop();
            }
            else{
                st.Push(c);
            }
        }
        char[] lc = st.ToArray();
        return new string(lc);
    }
}