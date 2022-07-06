class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
       
        int pp = 0, p = 1;
        for(int i = 2; i <= n; i++){
            int c = p + pp;
            pp = p;
            p = c;
        }
        
        return p;
    }
};