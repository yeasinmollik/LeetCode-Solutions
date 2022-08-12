class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();  
        unordered_map<int, int> cnt, ccnt;
        for(int i = 0; i < n; i++){
            cnt[arr[i]]++;    
        }
        
        for(auto x: cnt){
            if(ccnt[x.second])
                return false;
            ccnt[x.second]++;
        }
        return true;
    }
};