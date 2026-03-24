class Solution {
private:
    void evict(queue<pair<int, int>>& evict, queue<pair<int, int>>& oppo) {
        oppo.pop();
        auto& p = evict.front();
        evict.push({p.first+1, p.second});
        evict.pop();
    }
public:
    string predictPartyVictory(string senate) {
        queue<pair<int, int>> r,d;
        for(int i=0;i<senate.length();++i) {
            if(senate[i]=='R')
                r.push({1,i});
            else
                d.push({1,i});
        }
        while(!r.empty() && !d.empty()) {
            if(r.front().first<d.front().first)
                evict(r, d);
            else if(d.front().first<r.front().first)
                evict(d, r);
            else if(r.front().second<d.front().second)
                evict(r, d);
            else
                evict(d, r);
        }
        return r.empty()?"Dire":"Radiant";
    }
};