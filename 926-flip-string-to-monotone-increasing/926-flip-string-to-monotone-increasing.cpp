class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        int ones = 0;
        for(char &c: s)
            ones += c == '1';
        int ans = min(ones, n - ones);
        
        int left_ones = 0;
        for(int i = 0; i < n; i++){
            int right_zeroes = n - i - (ones - left_ones);
            ans = min(ans, right_zeroes + left_ones);
            
            left_ones += s[i] == '1';
        }
        return ans;
    }
};