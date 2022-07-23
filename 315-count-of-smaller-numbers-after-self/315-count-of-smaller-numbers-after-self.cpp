class Solution {
public:
    int mx = 20010;
    int bit[20010] = {};
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        int one = 10001;
        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] = query(nums[i] + one -1);
            update(nums[i] + one, 1);
        }
        return ans;
    }
    
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx&(-idx);
        }
        return sum;
    }
    
    void update(int idx, int val){
        while(idx < mx){
            bit[idx] += val;
            idx += idx&(-idx);
        }
    }
};