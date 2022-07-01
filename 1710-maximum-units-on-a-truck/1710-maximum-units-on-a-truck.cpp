class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] >= b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int ans = 0;
        for(auto &x: boxTypes){
            int lim = min(truckSize, x[0]);
            ans += x[1] * lim;
            truckSize -= lim;
        }
        
        return ans;
    }
};