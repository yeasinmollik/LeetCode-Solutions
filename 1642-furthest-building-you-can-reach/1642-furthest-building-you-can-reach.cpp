class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long mx_sum = 0, sum = 0, ans = 0;
        for(int i = 1; i < n; i++) {
            if(heights[i] > heights[i-1]){
                int diff = heights[i] - heights[i-1];
                sum += diff;
                
                if(pq.size() < ladders)
                    mx_sum += diff, pq.push(diff);
                else if(!pq.empty() && pq.top() < diff){
                        mx_sum -= pq.top();
                        pq.pop();
                        
                        mx_sum += diff;
                        pq.push(diff);
                }
            }
            if(sum - mx_sum <= bricks)
                    ans = i;
        }
        return ans;
    }
};