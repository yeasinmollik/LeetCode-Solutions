class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        st.push({s[0], 1});
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(st.size() && s[i] == st.top().first){
                int cnt = st.top().second + 1;
                st.pop();
                if(cnt < k)
                    st.push({s[i], cnt});
            }
            else
                st.push({s[i], 1});
        }
        string ans;
        while(st.empty() == false){
            auto[ch, cnt] = st.top();
            st.pop();
            for(int i = 0; i < cnt; i++)
                ans.push_back(ch);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};