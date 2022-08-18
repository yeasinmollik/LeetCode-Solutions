class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int cnt[100010] = {};
        for(int x: arr)
            cnt[x]++;
        
        sort(cnt, cnt + 100010, greater<int>());
        int to_remove = arr.size()/2;
        for(int i = 0; i < 100010; i++){
            to_remove -= cnt[i];
            if(to_remove <= 0)
                return i + 1;
        }
        return 0;
    }
};