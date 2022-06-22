class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        
        int prefix_sum = 0;
        int number_of_subarrays = 0;
        
        for(int &x: nums) {
            prefix_sum += x;
            number_of_subarrays += count[prefix_sum - k];
            count[prefix_sum]++;
        }
        return number_of_subarrays;
    }
};