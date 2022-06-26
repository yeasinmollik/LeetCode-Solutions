class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mod;
        mod[0] = 1;
        
        int sum = 0, ans = 0;
        for(int &x: nums){
            sum += x;
            int m = ((sum % k) + k) % k; //handles when m < 0
            ans += mod[m];
            mod[m]++;
        }
        
        return ans;
    }
};