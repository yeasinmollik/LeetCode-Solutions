class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for(char &c: s)
            m[c]++;
        
        vector<pair<int, char>> v;
        for(auto &x: m)
            v.push_back({x.second, x.first});
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        
        if((v[0].first - 1) > (s.size() - v[0].first))
            return "";
        
        vector<string> vs(v[0].first);
        
        for(int i = 0; i < vs.size(); i++)
            vs[i].push_back(v[0].second);
        
        int curr = 0;
        for(int i = 1; i < v.size(); i++) {
            for(int j = 0; j < v[i].first; j++, curr++){
                vs[curr % vs.size()].push_back(v[i].second);
            }
        }
        
        string res;
        for(string &s: vs)
            res += s;
        return res;
    }
};