class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt[1000010] = {};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                cnt[nums[i] - nums[j]]++;
            }
        }
        
        int c = 0;
        for(int i = 0; i < 1000010; i++){
            c += cnt[i];
            if(c >= k)
                return i;
        }
        return 1000000;
    }
};