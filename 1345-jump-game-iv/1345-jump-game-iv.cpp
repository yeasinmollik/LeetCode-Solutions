class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, set<int>> m;
        for(int i = 0; i < arr.size(); i++)
            m[arr[i]].insert(i);
        
        queue<pair<int, int>> q; // <index, jumps>
        q.push({0, 0});
        bool vis[50010] = {};
        vis[0] = true;
        m[arr[0]].erase(0);
        
        while(!q.empty()){
            auto[idx, jumps] = q.front();
            q.pop();
            
            if(idx == n - 1)
                return jumps;
            
            for(auto it = m[arr[idx]].begin(); it != m[arr[idx]].end();){
                q.push({*it, jumps + 1});
                vis[*it] = true;
                it = m[arr[idx]].erase(it);
            }
            
            int prev = idx - 1, next = idx + 1;
            if(prev >= 0 && !vis[prev])
                q.push({prev, jumps + 1}), vis[prev] = true, m[arr[prev]].erase(prev);
            
            if(next < n && !vis[next])
                q.push({next, jumps + 1}), vis[next] = true, m[arr[next]].erase(next);
        }
        return false;
    }
};