class Solution {
public:
    int zero = 1e4 + 1;
    int mx = 2 * zero + 1;
    int bt[20010] = {};
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lis = 1;
        for(int i = 0; i < n; i++){
            int lis_here = query(nums[i] + zero - 1) + 1;
            if(lis_here > lis)
                lis = lis_here;
            update(nums[i] + zero, lis_here);
        }
        
        return lis;
    }
    
    void update(int idx, int val){
        while(idx < mx){
            bt[idx] = max(bt[idx], val);
            idx += idx & (-idx);
        }
    }
    
    int query(int idx){
        int mx = 0;
        while(idx > 0){
            mx = max(mx, bt[idx]);
            idx -= idx & (-idx);
        }
        return mx;
    }
};