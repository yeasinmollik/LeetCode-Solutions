class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for(string s: paths){
            vector<string> v = split(s);
            string folder = v[0];
            for(int i = 1; i < v.size(); i++){
                string filename, content;
                for(int j = 0; j < v[i].size(); j++){
                    if(v[i][j] == '('){
                        for(int k = j + 1; v[i][k] != ')'; k++)
                            content += v[i][k];
                        break;
                    }
                    else filename += v[i][j];
                }
                mp[content].push_back(folder +"/"+ filename);
            }
        }
        vector<vector<string>> ans;
        for(auto x: mp)
            if(x.second.size() > 1)
                ans.push_back(x.second);
        return ans;
    }
    
    vector<string> split(string &s){
        s += ' ';
        vector<string> v;
        string w;
        
        for(char c: s){
            if(c == ' '){
                if(!w.empty())
                    v.push_back(w);
                w = "";
            }
            else
                w += c;
        }
        return v;
    }
};