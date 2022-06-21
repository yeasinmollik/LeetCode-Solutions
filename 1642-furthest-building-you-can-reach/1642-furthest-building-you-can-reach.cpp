class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long bricks_needed = 0;
        
        for(int i = 1; i < n; i++) {
            if(heights[i] > heights[i-1]){
                int diff = heights[i] - heights[i-1];
                
                if(pq.size() < ladders)
                    pq.push(diff);
                else if(!pq.empty() && pq.top() < diff){
                        bricks_needed += pq.top();
                        pq.pop();
                        pq.push(diff);
                }
                else
                    bricks_needed += diff;
            }
            if(bricks_needed > bricks)
                return i-1;
        }
        return n-1;
    }
};