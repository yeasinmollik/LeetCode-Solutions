class Solution {
public:
    int n;
    int dp[1010];
    
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, solve(i, d, arr));
            //cout << i << " " << dp[i]  + 1<< endl;
        }
        return ans + 1;
    }
    
    int solve(int i, int d, vector<int> &arr){
        if(dp[i] != -1)
            return dp[i];
        
        int mx = 0;
        
        int left = max(0, i - d);
        for(int j = i - 1; j >= left && arr[j] < arr[i]; j--){
            mx = max(mx, 1 + solve(j, d, arr));
        }

        int right = min(n - 1, i + d);
        for(int j = i + 1; j <= right && arr[j] < arr[i]; j++){
            mx = max(mx, 1 + solve(j, d, arr));
        } 
        
        return dp[i] = mx;
    }
};