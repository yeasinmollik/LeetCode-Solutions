class Solution {
public:
    int concatenatedBinary(int n) {
        int ans = 0, mod = 1e9 + 7;
        
        for(int i = n, pw = 1; i >= 1; i--){
            int num = i;
            while(num){
                int d = num % 2;
                ans = (ans + (pw * d)%mod)%mod;
                pw = (pw * 2)%mod;
                num /= 2;
            }
        }
        return ans;
    }
};