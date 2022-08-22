class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        
        if(n <= 2)
            return n == 1;
        
        int cnt = 0;
        while(n > 1){
            if(n % 2 != 0)
                return false;
            n/=2;
            cnt++;
        }
        return cnt % 2 == 0;
    }
};