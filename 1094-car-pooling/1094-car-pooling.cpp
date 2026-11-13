class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for(const auto& v:trips) {
            m[v[1]]+=v[0];
            m[v[2]]-=v[0];
        }
        for(const auto& [time, cnt]: m) {
            capacity-=cnt;
            if(capacity < 0)
                return false;
        }
        return true;
    }
};