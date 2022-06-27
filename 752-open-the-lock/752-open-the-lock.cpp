class Solution {
public:    
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> de;
        for(auto &s: deadends)
            de[s] = true;
        
        //if the source "0000" is a deadend, its impossible to reach target
        if(de["0000"])
            return -1;
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        
        unordered_map<string, bool> visited;
        visited["0000"] = true;
        
        while(!q.empty()){
            auto [curr, turns] = q.front();
            q.pop();
            
            if(curr == target)
                return turns;
            
            for(int i = 0; i < 4; i++){
                curr[i] = (curr[i] - '0' - 1 + 10) % 10 + '0';
                if(!de.count(curr) && !visited.count(curr))
                    q.push({curr, turns + 1}), visited[curr] = true;
                curr[i] = (curr[i] - '0' + 1 + 10) % 10 + '0';
                
                curr[i] = (curr[i] - '0' + 1 + 10) % 10 + '0';
                if(!de.count(curr) && !visited.count(curr))
                    q.push({curr, turns + 1}), visited[curr] = true;
                curr[i] = (curr[i] - '0' - 1 + 10) % 10 + '0';
            }
        }
        return -1;
    }
};