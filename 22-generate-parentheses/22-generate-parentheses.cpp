class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int m = 2*n;
        int mx = 1<<m;
        vector<string> ans;
        
        for(int i = 0; i < mx; i++){
            if(__builtin_popcount(i) != n)
                continue;
            
            int sum = 0, valid = 1; 
            for(int j = 0; j < m; j++){
                sum += (i & (1 << j))? 1 : -1;
                if(sum < 0){
                    valid = 0;
                    break;
                }
            }
            
            if(valid)
                ans.emplace_back(buildParenthesis(i, m));
        }   
        return ans;
    }
    
    string buildParenthesis(int &x, int &m){
        string s;
        for(int i = 0; i < m; i++){
            if(x & (1 << i))
                s.push_back('(');
            else
                s.push_back(')');
        }
        return s;
    }
};