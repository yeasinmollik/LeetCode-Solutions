class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a, b;
        
        for(char &c: s){
            if(c == '#' && !a.empty()) 
                a.pop();
            else if(c != '#')
                a.push(c);
        }
        
        for(char &c: t){
            if(c == '#' && !b.empty())
                b.pop();
            else if(c != '#')
                b.push(c);
        }
        
        string ss, tt;
        while(!a.empty())
            ss.push_back(a.top()), a.pop();
        
        while(!b.empty())
            tt.push_back(b.top()), b.pop();
        
        cout << ss << " " << tt << endl;
        return ss == tt;
    }
};