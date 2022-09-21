class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i]&1? 0 : nums[i];
        }
        vector<int> ans;
        for(int i = 0; i < q; i++){
            int idx = queries[i][1], val = queries[i][0];
            if(nums[idx] % 2 == 0){
                if(val & 1)
                    sum -= nums[idx];
                else
                    sum += val;
                nums[idx] += val;
            }
            else{
                if(val & 1)
                    sum += nums[idx] + val;
                nums[idx] += val;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};