class Solution {
public:
    vector<int> g[125];
    int color[125] = {};
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        for(string &s: equations)
            if(s[1] == '=')
                g[s[0]].emplace_back(s[3]), g[s[3]].emplace_back(s[0]);
        
        int c = 1;
        for(int i = 97; i <= 122; i++){
            if(!color[i]){
                dfs(i, c);
                c++;
            }
        }
        
        for(string &s: equations)
            if(s[1] == '!' && color[s[0]] == color[s[3]])
                return false;
        return true;
    }
    
    void dfs(int u, int &c){
        color[u] = c;
        
        for(int &v: g[u]){
            if(!color[v])
                dfs(v, c);
        }
    }
};