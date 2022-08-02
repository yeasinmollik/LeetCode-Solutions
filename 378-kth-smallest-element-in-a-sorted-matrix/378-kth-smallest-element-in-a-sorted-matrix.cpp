typedef tuple<int, int, int> tupl;

class Solution {
public:
    int n, m, inf = 1e9 + 7;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size(), m = matrix[0].size();
        int cnt = 0, ans;
        
        priority_queue<tupl, vector<tupl>, greater<tupl>> pq;
        for(int i = 0; i < m && i < k; i++){
            pq.push({matrix[0][i], 0, i});
        }
        for(int l = 0; l < k; l++){
            auto[val, i, j] = pq.top();
            pq.pop();
            
            ans = val;
            if(i + 1 < n)
                pq.push({matrix[i+1][j], i + 1, j});
            cnt++;
        }
        return ans;
    }
};