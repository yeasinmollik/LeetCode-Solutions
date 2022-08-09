class Solution {
public:
    int n;
    int mod = 1e9 + 7;
    int dp[1010] = {};
    unordered_map<int, int> idx;
    vector<pair<int, int>> divs[1010];
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++)
            idx[arr[i]] = i;
        
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(arr[i] <= arr.back() / arr[j] && idx.count(arr[i] * arr[j]))
                    divs[idx[arr[i] * arr[j]]].emplace_back(i, j);
        
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for(int i = n - 1; i>= 0; i--){
            ans = (ans + get(i))%mod;
        }
        return ans;
    }
    
    long long get(int x){
        if(dp[x] != -1)
            return dp[x];

        long long tot = 1;
        for(auto d: divs[x]){
            if(d.first != d.second)
                tot = (tot + (2 * (get(d.first) * get(d.second)) % mod) % mod)%mod;
            else
                tot = (tot + (get(d.first) * get(d.second)) % mod) % mod;
        }
        return dp[x] = tot;
    }
};