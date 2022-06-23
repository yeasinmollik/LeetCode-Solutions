class Solution {
public:
    bool vis[100010] = {};
    vector<int> g[100010];
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i = 0; i < connections.size(); i++){
            g[connections[i][0]].emplace_back(connections[i][1]);
            g[connections[i][1]].emplace_back(connections[i][0]);
        }
        
        int connected_components = 0, extra_edges = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                int nodes = 0, edges = 0;
                connected_components++;
                
                dfs(i, nodes, edges);
                
                //every edges is counted twice. So, divide total edges by 2
                extra_edges += (edges / 2) - (nodes - 1);
            }
        }
        
        int ans = -1;
        if(extra_edges >= connected_components - 1)
            ans = connected_components - 1;

        return ans;
    }
    
    void dfs(int u, int &nodes, int &edges){
        vis[u] = true;
        edges += g[u].size();
        nodes++;
        
        for(int &v: g[u]){
            if(!vis[v])
                dfs(v, nodes, edges);
        }
    }
};