//similar idea as Sliding Window Maximum

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        deque<int> dq;
        int max_value = INT_MIN;
        
        for(int r = 0; r < n; r++){
            //removing out of range points
            while(!dq.empty() && (points[r][0] - points[dq.front()][0]) > k)
                dq.pop_front();
            
            if(!dq.empty())
                max_value = max(max_value, points[r][0] + points[r][1] + points[dq.front()][1] - points[dq.front()][0]);
            
            // removing points having y - x values less than points[r]
            int y_minus_x = points[r][1] - points[r][0];
            while(!dq.empty() && points[dq.back()][1] - points[dq.back()][0] < y_minus_x)
                dq.pop_back();
            dq.push_back(r);
        }
        return max_value;
    }
};