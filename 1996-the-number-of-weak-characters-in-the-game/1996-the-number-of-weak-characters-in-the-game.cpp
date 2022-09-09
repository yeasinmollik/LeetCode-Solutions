class Solution {
public:   
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(), props.end(), greater<vector<int>>());
        int n = props.size();
        
        int ans = 0, globalMx = 0, mx = props[0][1];
        for(int i = 1; i < n; i++){
            if(props[i][0] == props[i-1][0])
                mx = max(mx, props[i][1]);
            else 
                globalMx = max(globalMx, mx), mx = props[i][1];
            
            ans += props[i][1] < globalMx;
        }
        return ans;        
    }
};