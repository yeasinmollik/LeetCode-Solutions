class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> exists;
        unordered_map<int, bool> done;
        
        for(int &x: nums)
            exists[x] = true;
        
        int longest = 0;
        for(int i = 0; i < nums.size(); i++){
            if(done[nums[i]] || exists[nums[i] - 1])
                continue;
            
            int cnt = 0, num = nums[i];
            while(exists[num])
               done[num] = true, num++, cnt++;
            
            longest = max(longest, cnt);
        }
        
        return longest;
    }
};