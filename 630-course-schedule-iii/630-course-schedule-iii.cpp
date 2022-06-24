class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];    
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        int n = courses.size();
        
        priority_queue<int> pq;
        int time = 0;
        for(int i = 0; i < n; i++) {
            int duration = courses[i][0];
            int limit = courses[i][1];
            
            time += duration;
            pq.push(duration);
            
            if(time > limit){
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};