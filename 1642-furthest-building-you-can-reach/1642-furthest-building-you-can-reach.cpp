class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long sum = 0;
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(heights[i] > heights[i-1]){
                int diff = heights[i] - heights[i-1];
                
                if(pq.size() < ladders)
                    pq.push(diff);
                else if(!pq.empty() && pq.top() < diff){
                        sum += pq.top();
                        pq.pop();
                        pq.push(diff);
                }
                else
                    sum += diff;
            }
            if(sum <= bricks)
                    ans = i;
        }
        return ans;
    }
};