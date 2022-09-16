class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int x: nums)
            cnt[x]++;
        
        unordered_map<int, vector<int>> same_cnt;
        for(auto x: cnt)
            same_cnt[x.second].push_back(x.first);
        
        vector<int> ans;
        for(int i = n; i >= 1 && k; i--){
            for(int &x: same_cnt[i])
                ans.push_back(x);
            k -= same_cnt[i].size();
        }
        return ans;
    }
};