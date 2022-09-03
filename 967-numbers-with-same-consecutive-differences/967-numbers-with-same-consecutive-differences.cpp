class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++)
            solve(1, i, k, n, ans);
        return ans;
    }
    
    void solve(int count, int number, int k, int n, vector<int> &ans){
        if(count == n){
            ans.emplace_back(number);
            return;
        }
        
        int lastDigit = number % 10;
        if(lastDigit - k >= 0)
            solve(count + 1, number * 10 + lastDigit - k, k, n, ans);
        if(k && lastDigit + k <= 9)
            solve(count + 1, number * 10 + lastDigit + k, k, n, ans);
    }
};