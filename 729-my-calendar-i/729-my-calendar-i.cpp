class MyCalendar {
public:
    vector<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto e: events){
            if(intersect(e, make_pair(start, end - 1)))
                return false;
        }
        events.push_back({start, end - 1});
        return true;
    }
    
    bool intersect(pair<int, int> a, pair<int, int> b){
        return !(a.second < b.first || a.first > b.second);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */