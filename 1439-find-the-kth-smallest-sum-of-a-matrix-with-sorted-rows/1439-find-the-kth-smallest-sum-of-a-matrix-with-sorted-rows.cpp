class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += mat[i][0];
        
        vector<int> v(n + 1); //v[0] = sum, and v[1....n] = indexes
        v[0] = sum;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push(v);
        
        map<vector<int>, bool> already;
        int ans = sum;
        
        for(int i = 0; i < k; ){
            auto w = pq.top();
            pq.pop();
            
            if(already.find(w) != already.end())
                continue;
            
            ans = sum = w[0];
            already[w] = true;
            
            for(int j = 1; j <= n; j++) {
                int col = w[j];
                
                if(col + 1 < m) {
                    w[0] = sum - mat[j-1][col] + mat[j-1][col + 1];
                    w[j] = col + 1;
                    
                    if(already.find(w) == already.end())
                        pq.push(w);
                
                    w[j] = col;
                    w[0] = sum;
                }
            }
            i++;
        }
        
        return ans;
    }
};