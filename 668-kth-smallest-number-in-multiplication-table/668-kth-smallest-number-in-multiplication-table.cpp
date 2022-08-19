class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        int ans = m * n;
        
        while(left <= right){
            int mid  = (left + right)/2;
            int cnt = count(m, n, mid);
            if(cnt >= k)
                right = mid - 1, ans = mid;
            else 
                left = mid + 1;
        }
        return ans;
    }
    
    int count(int m, int n, int num){
        int cnt = 0;
        for(int i = 1; i <= m; i++){
            cnt += min(n, num / i);
        }
        return cnt;
    }
};
