### Binary Search
Some thinking got me the intuition that, we should always try to use ladders for the buildings with higher height difference.

For example, if $[1, 2, 1, 10]$ are the heights of buildings and we have one ladder and one brick, we should use the ladder to move from building 3 to building 4 and use that one brick to move from building 1 to building 2. Using ladders for higher height differences and using bricks for the rest is the most optimal approach!

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

### Priority Queue
This approach is better than the above approach! The main idea is, while moving from the left to the right, we keep track of $ladders$ number of the greatest height differences using a min-priority_queue. We use ladders for these larger height difference and the given bricks are used for lower height differnces. If at any point the given number of bricks aren't enough to resolve those lower height differences, we stop right there. 

```cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        // ladders are reserverd for larger height differences are reserved
        // min priority-queue is used to keep track of larger height differences
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
```
