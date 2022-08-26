class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int pw[31];
        for(int i = 0; i <= 30; i++)
            pw[i] = (1<<i);
        
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if(s.front() != '0' && binary_search(begin(pw), end(pw), stol(s)))
                return true;
        }while(next_permutation(s.begin(), s.end()));
        return false;
    }
};