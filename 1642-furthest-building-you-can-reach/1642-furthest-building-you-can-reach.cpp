class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        int l = 0, r = n-1, ans = 0;
        while(l <= r){
            int m = (l + r)/2;
            
            if(okay(heights, m, bricks, ladders))
                l = m + 1, ans = m;
            else
                r = m - 1;
        }      
        return ans;
    }
    
    bool okay(vector<int> &heights, int target, int bricks, int ladders){
        vector<int> diffs;
        for(int i = 1; i <= target; i++) {
            if(heights[i] > heights[i-1])
                diffs.emplace_back(heights[i] - heights[i-1]);
        }   
        
        if(diffs.size() <= ladders)
            return true;
        
        int k = diffs.size() - ladders;
        priority_queue<int> pq;
        for(int i = 0; i < k; i++)
            pq.push(diffs[i]);
        
        for(int i = k; i < diffs.size(); i++){
            if(diffs[i] < pq.top()) {
                pq.pop();
                pq.push(diffs[i]);
            }
        }
        
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum <= bricks;
    }
};