class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_left = height[0], max_right = height.back();
        int max_area = 0;
        int l = 0, r = height.size() - 1;
        while(l < r){
            if(height[l] < height[r]){
                max_area = max(max_area, height[l] * (r - l));
                l++;
            }
            else{
                max_area = max(max_area, height[r] * (r - l));
                r--;
            }
        }
        return max_area;
    }
};