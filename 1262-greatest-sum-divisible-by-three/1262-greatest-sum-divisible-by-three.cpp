class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> mod[3];
        int sum = 0;
        for(int &x: nums){
            sum += x;
            mod[x % 3].push_back(x);
        }
        
        for(int i = 0; i < 3; i++)
            sort(mod[i].begin(), mod[i].end());
        
        int ans;
        int md = sum % 3;
        
        if(md == 1) {
            ans = INT_MIN;
            if(mod[1].size())
                ans = max(ans, sum - mod[1][0]);
            if(mod[2].size() >= 2)
                ans = max(ans, sum - mod[2][0] - mod[2][1]);
        }
        else if(md == 2){
            ans = INT_MIN;
            if(mod[2].size())
                ans = max(ans, sum - mod[2][0]);
            if(mod[1].size() >= 2)
                ans = max(ans, sum - mod[1][0] - mod[1][1]);
        }
        else
            ans = sum;
        
        return ans;
    }
};