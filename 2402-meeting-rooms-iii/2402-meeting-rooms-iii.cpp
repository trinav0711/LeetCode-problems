class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());
        vector<long> end(n, 0);
        map<long, set<int>> m;
        for(const auto& v:meetings) {
            int i;
            for(i=0;i<cnt.size();++i) {
                if(end[i]<=static_cast<long>(v[0])) {
                    ++cnt[i];
                    if(m.find(end[i]) != m.end()) {
                        m[end[i]].erase(i);
                        if(m[end[i]].empty())
                            m.erase(end[i]);
                    }
                    end[i]=static_cast<long>(v[1]);
                    m[end[i]].insert(i);
                    break;
                }
            }
            if(i>=cnt.size()) {
                auto first=m.begin()->first;
                i=*(m[first].begin());
                ++cnt[i];
                m[first].erase(i);
                if(m[first].empty())
                    m.erase(first);
                end[i]=first+static_cast<long>(v[1]-v[0]);
                m[end[i]].insert(i);
            }
        }
        int idx=0;
        for(int i=1;i<cnt.size();++i) {
            if(cnt[i]>cnt[idx])
                idx=i;
        }
        return idx;
    }
};