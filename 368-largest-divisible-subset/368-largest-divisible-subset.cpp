class Solution {
public:
    vector<short> adj[1010];
    int dp[1010];
    int next[1010];
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < i; j++)
                if(nums[i] % nums[j] == 0)
                    adj[j].emplace_back(i);
        
        memset(dp, -1, sizeof(dp));
        memset(next, -1, sizeof(next));
        int mxSubset = 1, first = 0;
        for(int i = 0; i < nums.size(); i++){
            int gt = get(i);
            if(gt > mxSubset)
                mxSubset = gt, first = i;
        }
        
        vector<int> subset = {nums[first]};
        while(next[first] != -1)
            subset.emplace_back(nums[next[first]]), first = next[first];
        
        return subset;
    }
    
    int get(int u){
        if(dp[u] != -1)
            return dp[u];
        
        dp[u] = 1;
        for(short &v: adj[u]){
            int gt = get(v) + 1;
            if(gt > dp[u])
                dp[u] = gt, next[u] = v;
        }
        return dp[u];
    }
};