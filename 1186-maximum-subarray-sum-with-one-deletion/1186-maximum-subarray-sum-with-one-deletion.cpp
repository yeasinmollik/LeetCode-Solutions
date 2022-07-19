class Solution {
public:
    int n;
    
    int maximumSum(vector<int>& arr) {
        n = arr.size();    
        vector<int> ends(n);
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            ends[i] = sum;
            if(sum < 0)
                sum = 0;
        }
        
        vector<int> starts(n);
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            sum += arr[i];
            starts[i] = sum;
            if(sum < 0)
                sum = 0;
        }
        
        int mxx = max(*max_element(starts.begin(), starts.end()), *max_element(ends.begin(), ends.end()));
        
        for(int i = 1; i + 1 < n; i++)
            mxx = max(mxx, ends[i-1] + starts[i + 1]);
        return mxx;
    }
};