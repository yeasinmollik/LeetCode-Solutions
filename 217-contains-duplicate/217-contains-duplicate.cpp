class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> before;
        for(int x: nums){
            if(before[x])
                return true;
            before[x] = true;
        }
        return false;
    }
};