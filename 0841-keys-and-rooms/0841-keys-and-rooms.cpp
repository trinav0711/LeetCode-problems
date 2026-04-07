class Solution {
private:
    void dfs(set<int>& s, int cur, vector<vector<int>>& v) {
        s.insert(cur);
        for(int x:v[cur]) {
            if(s.find(x)==s.end())
                dfs(s, x, v);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int>visit;
        dfs(visit, 0, rooms);
        return visit.size()==rooms.size();
    }
};