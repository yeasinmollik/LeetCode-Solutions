class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> ans;
        deque<int> dq;
        
        for(int r = 0; r < n; r++){
            //removing out of range numbers
            if(!dq.empty() && dq.front() < (r - k + 1))
                dq.pop_front();
            
            //removing previous numbers less than nums[r] as they will never be maximum of any future windows
            while(!dq.empty() && nums[dq.back()] <= nums[r])
                dq.pop_back();
            dq.push_back(r);
            
            //because of the way numbers are inserted in the deque, deque.front() will have the largest number in the current window of size k 
            if(r >= k-1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};