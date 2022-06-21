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
        sort(diffs.begin(), diffs.end(), greater<int>());
        
        int sum = 0;
        for(int i = ladders; i < diffs.size(); i++)
            sum += diffs[i];
        
        return sum <= bricks;
    }
};