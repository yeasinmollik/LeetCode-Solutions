class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();       
        if(n == 1)  return 1;
        
        //sorting base on the inceasing starting value
        sort(points.begin(), points.end(), cmp);
        
        // dummy point to make the code concise and clean
        points.push_back({INT_MAX, INT_MIN});  
        int shots = 0;
        auto prev = points.front();
        
        for(int i = 1; i <= n; i++){
            if(dontOverlap(prev, points[i])) 
                shots++, prev = points[i];
            else
                prev = {points[i][0], min(prev[1], points[i][1])};
        }
        
        return shots;
    }
    
    bool dontOverlap(vector<int> &a, vector<int> &b){
        return b[0]  > a[1] || b[1] < a[0];
    }
};