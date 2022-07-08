class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 1)
            return 1;
        
        int n = points.size();       
        sort(points.begin(), points.end()); 
        points.push_back({INT_MAX, INT_MIN});  
        int shots = 0;
        auto prev = points.front();
        for(int i = 1; i <= n; i++){
            if(overlaps(prev, points[i]))
                prev = {points[i][0], min(prev[1], points[i][1])};
            else 
                shots++, prev = points[i];
        }
        return shots;
    }
    
    bool overlaps(vector<int> &a, vector<int> &b){
        return !(b[0]  > a[1] || b[1] < a[0]);
    }
};