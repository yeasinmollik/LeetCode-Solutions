class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        vector<int> p(n), s(n);
        int ps = 0, ss = 0;
        for(int i = 0, j = n -1; i < n; i++, j--){
            ps += cardPoints[i];
            ss += cardPoints[j];
            p[i] = ps;
            s[j] = ss;
        }
        reverse(s.begin(), s.end());
        
        int ans = max(p[k-1], s[k-1]); 
        for(int i = 1; i < k; i++)
            ans = max(ans, p[i-1] + s[k - i - 1]);
        
        return ans;
    }
};