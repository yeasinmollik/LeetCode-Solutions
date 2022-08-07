typedef tuple<int, int, int> tupl;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tupl, vector<tupl>, greater<tupl>> pq;
        for(int i = 0; i < n; i++)
            pq.push({matrix[0][i], 0, i});
        
        int ans;
        for(int i = 0; i < k; i++){
            auto [val, x, y] = pq.top();
            pq.pop();
            ans = val;
            if(x + 1 < n)
                pq.push({matrix[x + 1][y], x + 1, y});
        }
        return ans;
    }
};
    
