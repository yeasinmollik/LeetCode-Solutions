public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        int n = nums.Length;
        IList<IList<int>> res = new List<IList<int>>();
        
        Array.Sort(nums);
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int l = i + 1, r = n-1, target = -nums[i];
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    IList<int> temp = new List<int>();
                    temp.Add(nums[i]);
                    temp.Add(nums[l]);
                    temp.Add(nums[r]);
                    res.Add(temp);
                    while(l < r && nums[l+1] == nums[l])
                        l = l + 1;
                    while(r > l && nums[r-1] == nums[r])
                        r = r - 1;
                    l = l + 1;
                    r = r - 1;
                }
                else if(sum > target)
                    r = r -1;
                else
                    l = l + 1;
            }
        }
        return res;
    }
}