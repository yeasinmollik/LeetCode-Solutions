class Solution {
public:
    int n;
    vector<int> adj[1010];
    int dp[1010];
    bool vis[1010] = {};
    int next[1010] = {};
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(nums[j] % nums[i] == 0)
                    adj[i].emplace_back(j);
                    
        memset(dp, -1, sizeof(dp));
        memset(next, -1, sizeof(next));
        
        int mx = 1, first = 0;
        for(int i = 0; i < n; i++){
            if(mx < solve(i))
                mx = solve(i), first = i;
        }
        
        vector<int> ans = {nums[first]};
        while(next[first]!=-1)
            ans.emplace_back(nums[next[first]]), first = next[first];

        return ans;
    }
    
    int solve(int u){
        if(dp[u]!=-1)
            return dp[u];
        
        dp[u] = 1;
        for(int &v: adj[u]){
            int slv = solve(v) + 1;
            if(slv > dp[u])
                dp[u] = slv, next[u] = v;            
        }
        
        return dp[u];
    }
};
