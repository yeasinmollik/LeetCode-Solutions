class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)
            return stones[0];
        
        int tot = 0;
        for(int &x: stones)
            tot += x;
        
        bool last[3010] = {}, curr[3010] = {};
        
        last[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= tot; j++){
                curr[j] = last[j];
                if(j >= stones[i-1])
                    curr[j] = curr[j] | last[j - stones[i-1]];
            }
            copy(begin(curr), end(curr), begin(last));
        }
        
        for(int i = tot/2; i >= 1; i--)
            if(last[i])
                return tot - 2*i;
        
        return 0;
    }
};