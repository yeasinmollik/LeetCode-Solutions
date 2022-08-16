class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        bool exists[2020] = {};
        
        for(int i = 0; i < arr.size(); i++)
            exists[arr[i]] = true;
        
        for(int i = 1; i < 2010; i++){
            if(exists[i] == false)
                k--;
            if(k == 0)
                return i;
        }
        return 0;
    }
};