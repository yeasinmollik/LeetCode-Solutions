### Binary Search
Some thinking got me the intuition that, we should always try to use ladders for the buildings with higher height difference.

For example, if $[1, 2, 1, 10]$ are the heights of buildings and we have one ladder and one brick, we should use the ladder to move from building 3 to building 4 and use that one brick to move from building 1 to building 2. Using ladders for higher highet differences and using bricks for the rest is the most optimal approach!

I did a binary search on the building I want to move and checked if its possible to move there using above approach.


```cpp
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
    
    bool okay(vector<int> &h, int target, int bricks, int ladders){
        vector<int> diffs;
        for(int i = 1; i <= target; i++) {
            if(h[i] > h[i-1])
                diffs.emplace_back(h[i] - h[i-1]);
        }        
        sort(diffs.begin(), diffs.end(), greater<int>());
        
        int sum = 0;
        for(int i = ladders; i < diffs.size(); i++)
            sum += diffs[i];
        
        return sum <= bricks;
    }
};
```
