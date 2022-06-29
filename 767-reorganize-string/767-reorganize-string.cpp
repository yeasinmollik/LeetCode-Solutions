class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        sort(s.begin(), s.end());
        for(char &c: s)
            m[c]++;
        
        vector<pair<int, char>> v;
        for(auto &x: m)
            v.push_back({x.second, x.first});
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        // for(auto &x: v)
        //     cout << x.first << " " << x.second << endl;
        
        int needed = v[0].first - 1;
        int rem = s.size() - v[0].first;
        if(needed > rem)
            return "";
        
        vector<string> vs(v[0].first);
        
        for(int i = 0; i < vs.size(); i++)
            vs[i].push_back(v[0].second);
        
        for(int i = 0; i < s.size(); i++){
            if(s[i]!=v[0].second)
                vs[i % v[0].first].push_back(s[i]);
        }
        
        string res;
        for(string &s: vs)
            res += s;
        return res;
    }
};