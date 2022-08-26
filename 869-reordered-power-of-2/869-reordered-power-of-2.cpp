class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<long, bool> pw;
        for(int i = 0; i <= 32; i++)
            pw[(long)1<<i] = true;
        
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if(s.front() != '0' && pw[stol(s)])
                return true;
        }while(next_permutation(s.begin(), s.end()));
        return false;
    }
};