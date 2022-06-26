class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mod;
        mod[0] = 1;
        
        int sum = 0, ans = 0;
        for(int &x: nums){
            sum = (sum + x) % k;
            if(sum < 0)
                sum += k;
            ans += mod[sum];
            mod[sum]++;
        }
        return ans;
    }
};