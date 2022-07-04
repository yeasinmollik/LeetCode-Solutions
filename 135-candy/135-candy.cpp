class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> pos[20010];
        int n = r.size();
        r.insert(r.begin(), 1e9);
        r.push_back(1e9);
        
        set<int> s;
        for(int i = 1; i <= n; i++){
            pos[r[i]].emplace_back(i);
            s.insert(r[i]);
        }
        
        // for(auto &x: pos) {
        //     for(int &y: x.second)
        //         cout << y << " ";
        //     cout << endl;
        // }
        
        int ans = 0;
        int candies[20010] = {};
        
        for(int x: pos[*s.begin()])
            candies[x] = 1, ans++;
        
        for(auto it = next(s.begin()); it != s.end(); it++){
            for(int x: pos[*it]){
                if(r[x-1] >= r[x] && r[x + 1] >= r[x]) {
                    candies[x] = 1;
                    ans++;
                    continue;
                }
                
                int candy = 1;
                if(r[x-1] < r[x])
                    candy = candies[x - 1] + 1;
                if(r[x + 1] < r[x])
                    candy = max(candy, candies[x + 1] + 1);
                
                candies[x] = candy;
                ans += candy;
            }
        }
        
        for(int i = 1; i < r.size() - 1; i++)
            cout << candies[i] << " ";
            
        return ans;
    }
};
    