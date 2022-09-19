class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n)
            return false;
        
        int c1[128] = {};
        for(char c: s1)
            c1[c]++;
        
        int c2[128] = {};
        for(int i = 0; i < m; i++)
            c2[s2[i]]++;
        
        if(same(c1, c2))
            return true;
        
        for(int i = m; i < n; i++){
            c2[s2[i - m]]--;
            c2[s2[i]]++;
            if(same(c1, c2))
                return true;
        }
        return false;
    }
    
    bool same(int a[], int b[]){
        for(int i = 97; i < 123; i++)
            if(a[i] != b[i])
                return false;
        return true;
    }
};