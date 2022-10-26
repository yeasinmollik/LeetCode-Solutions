public class Solution {
    public int CalPoints(string[] ops) {
        int n = ops.Length;
        
        Stack<int> st = new Stack<int>();
        for(int i = 0; i < n; i++){
            if(ops[i] == "C")
                st.Pop();
            else if(ops[i] == "D"){
                st.Push(st.Peek() * 2);
            }
            else if(ops[i] == "+"){
                int last = st.Peek();
                st.Pop();
                int lLast = st.Peek();
                st.Push(last);
                st.Push(lLast + last);
            }
            else
                st.Push(Convert.ToInt32(ops[i]));
        }
        
        int answer = 0;
        while(st.Count > 0){
            answer += st.Peek();
            st.Pop();
        }
        return answer;
    }
}