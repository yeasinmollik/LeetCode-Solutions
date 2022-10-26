public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int n = nums.Length;
        Dictionary<int, int> dict = new Dictionary<int, int>();
        
        
        for(int i = 0; i < n; i++){
            int needed = target - nums[i];
            if(dict.ContainsKey(needed)){
                int[] res = {dict[needed], i};
                return res;
            }
            if(!dict.ContainsKey(nums[i]))
                dict.Add(nums[i], i);    
        }
        
        return nums;
    }
}