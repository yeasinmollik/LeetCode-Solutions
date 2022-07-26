class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(arr[curr] == 0)
                return true;
            
            int left = curr - arr[curr];
            int right = curr + arr[curr];
            
            if(left >= 0 && !vis[left])
                q.push(left), vis[left] = true;
            
            if(right < n && !vis[right])
                q.push(right), vis[right] = true;
        }
        return false;
    }
};