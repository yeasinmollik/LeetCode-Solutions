class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
        vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
        queue<pair<int, vector<vector<int>>>> q;
        unordered_map<string, bool> already;
        if(board == target)
            return 0;
        
        q.push({0, board});
        already[tostr(board)] = true;
        
        while(!q.empty()){
            auto [moves, v] = q.front();
            q.pop();
            
            if(v == target)
                return moves;
            
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if(v[i][j] == 0){
                        for(int k = 0; k < 4; k++){
                            int i1 = i + x[k], j1 = j + y[k];
                            if(valid(i1, j1)){
                                swap(v[i][j], v[i1][j1]);
                                string s = tostr(v);
                                if(!already[s]) {
                                    q.push({moves + 1, v});
                                    already[s] = true;
                                }
                                swap(v[i][j], v[i1][j1]);
                            }
                        }
                        break;
                    }
                }
            }
        }
        
        return -1;
    }
    
    string tostr(vector<vector<int>> &v){
        string s;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                s.push_back(v[i][j]);
            }
        }
        return s;
    }
        
    bool valid(int &i, int &j){
        return  i >= 0 && i < 2 && j >= 0 && j < 3;
    } 
};