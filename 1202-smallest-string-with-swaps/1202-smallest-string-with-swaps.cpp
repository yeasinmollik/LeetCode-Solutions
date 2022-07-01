class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vis.resize(n);
        adj.resize(n);
        
        for(auto &p: pairs)
            adj[p[0]].push_back(p[1]), adj[p[1]].push_back(p[0]);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                vector<int> connected;
                string t;
                dfs(i, connected, s, t);
                
                sort(t.begin(), t.end());
                sort(connected.begin(), connected.end());
                for(int j = 0; j < connected.size(); j++)
                    s[connected[j]] = t[j];
            }
        }
        return s;
    }
    
    void dfs(int u, vector<int>& connected, string &s, string& t){
        vis[u] = true;
        connected.push_back(u);
        t.push_back(s[u]);
        
        for(int &v: adj[u])
            if(!vis[v])
                dfs(v, connected, s, t);
    }
};