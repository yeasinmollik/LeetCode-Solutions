class Solution {
public:
    int maxArea(int h, int w, vector<int>& hz, vector<int>& vt) {
        hz.push_back(0);
        vt.push_back(0);
        hz.push_back(h);
        vt.push_back(w);
        sort(hz.begin(), hz.end());
        sort(vt.begin(), vt.end());
        
        int x = 0, y = 0;
        for(int i = 1; i < hz.size(); i++){
            x = max(x, hz[i] - hz[i-1]);
        }
        for(int i = 1; i < vt.size(); i++){
            y = max(y, vt[i] - vt[i-1]);
        }
        return ((long long)x * y) % (int)(1e9 + 7);
    }
};