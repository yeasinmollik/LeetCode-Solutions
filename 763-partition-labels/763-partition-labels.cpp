class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last[125];
        for(int i = 0; i < n; i++)
            last[s[i]] = i;
        
        int left = 0;
        vector<int> ans;
        while(left < n){
            int right = left;
            for(int i = left; i <= right; i++){
                right = max(right, last[s[i]]);
            }
            ans.emplace_back(right - left + 1);
            left = right  + 1;   
        }
        return ans;
    }
};