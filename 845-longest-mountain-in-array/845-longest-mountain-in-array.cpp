class Solution {
public: 
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int  left[10010] = {};
        
        int cnt = 1;
        left[0] = 1;
        
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i-1])
                cnt++;
            else
                cnt = 1;
            left[i] = cnt;
        }
        
        int ans = 0;
        int right = 1;
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[i + 1])
                right++;
            else
                right = 1;
            
            if(left[i] > 1 && right > 1)
                ans = max(ans, left[i] + right - 1);
        }
        
        return ans;
    }
};