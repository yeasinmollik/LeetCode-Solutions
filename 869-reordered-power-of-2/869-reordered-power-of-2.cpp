class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<long> pw;
        for(int i = 0; i <= 32; i++)
            pw.push_back((long)1<<i);
        
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if(s.front() != '0' && binary_search(pw.begin(), pw.end(), stol(s)))
                return true;
        }while(next_permutation(s.begin(), s.end()));
        return false;
    }
};