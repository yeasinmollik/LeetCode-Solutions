class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 2)
            return *min_element(cost.begin(), cost.end());
    
        int pprev = cost[0], prev = cost[1];
        
        for(int i = 2; i < cost.size(); i++){
            int curr = min(pprev, prev) + cost[i];
            pprev = prev;
            prev = curr;
        }
        
        return min(pprev, prev);
    }
};