class Solution {
public:
    int dp[13][100010];
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        memset(dp, -1, sizeof(dp));
        
        int arrows = numArrows, rem_arrows = numArrows;
        vector<int> bobArrows(12);
        for(int i = 0; i < 12; i++){
            // means bob choose the i'th target
            if(solve(i, arrows, aliceArrows) != solve(i + 1, arrows, aliceArrows)){
                bobArrows[i] = aliceArrows[i] + 1;
                arrows -= bobArrows[i];
                rem_arrows -= bobArrows[i];
            }
        }
        
        // must use all arrows. So, putting all remaining arrows at 0'th target.
        bobArrows[0] += rem_arrows;
        
        return bobArrows;
    }
    
    int solve(int idx, int arrows, vector<int>& aliceArrows){
        if(idx == 12 || arrows == 0)
            return 0;
        
        if(dp[idx][arrows] != -1)
            return dp[idx][arrows];
        
        int without = solve(idx + 1, arrows, aliceArrows);
        int with = (arrows >= aliceArrows[idx]+1 ? idx + solve(idx + 1, arrows - aliceArrows[idx]-1, aliceArrows) : 0);
        
        return dp[idx][arrows] = max(with, without);
    }
};