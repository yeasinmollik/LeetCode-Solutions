class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)
            return stones[0];
        
        int tot = 0;
        for(int &x: stones)
            tot += x;
        
        vector<bool> last(tot + 1, false);
        
        last[0] = true;
        for(int i = 1; i <= n; i++){
            vector<bool> curr(tot + 1);
            for(int j = 0; j <= tot; j++){
                curr[j] = last[j];
                if(j >= stones[i-1])
                    curr[j] = curr[j] | last[j - stones[i-1]];
            }
            last = curr;
        }
        
        for(int i = tot/2; i >= 1; i--)
            if(last[i])
                return tot - i - i;
        
        return 0;
    }
};