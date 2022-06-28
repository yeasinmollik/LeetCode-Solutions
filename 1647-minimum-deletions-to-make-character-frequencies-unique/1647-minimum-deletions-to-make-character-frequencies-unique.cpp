class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {};
        
        for(char &c: s)
            cnt[c - 'a']++;
        
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++)
            if(cnt[i])
                pq.push(cnt[i]);
        
        int deletes = 0;
        while(pq.size() >= 2){
            int a = pq.top();
            pq.pop();
            
            if(pq.top() == a){
                deletes++;
                if(a > 1)
                    pq.push(a - 1);
            }
        }
        
        return deletes;
    }
};