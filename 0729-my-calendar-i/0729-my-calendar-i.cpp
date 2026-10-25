class MyCalendar {
private:
    vector<pair<int,int>> v;
public:
    MyCalendar(): v{} {}
    
    bool book(int startTime, int endTime) {
        bool found=false;
        for(const auto& p:v) {
            if(!(startTime>=p.second || endTime<=p.first)) {
                found=true;
                break;
            }
        }
        if(!found)
            v.push_back({startTime, endTime});
        return !found;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */