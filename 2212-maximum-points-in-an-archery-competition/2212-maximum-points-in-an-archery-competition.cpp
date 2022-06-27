class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int max_points = 0;
        int res = 0;
        
        for(int i = 0; i < (1 << 12); i++){
            int arrows = 0, points = 0;
            for(int j = 0; j < 12; j++){
                if(i & (1 << j)){
                    arrows += aliceArrows[j] + 1;
                    if(arrows > numArrows)
                        break;
                    points += j;
                }
            }
            if(arrows <= numArrows && points > max_points)
                res = i, max_points = points;
        }
        
        vector<int> bobArrows(12);
        int arrows = 0;
        for(int i = 0; i < 12; i++){
            if(res & (1 << i))
                arrows += bobArrows[i] = aliceArrows[i] + 1;
        }
        // must use leftover arrows. so, distributed them to 0'th target 
        bobArrows[0] += numArrows - arrows;
        
        return bobArrows;
    }
};