class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        unordered_map<int, bool> m;

        for(int x:arr) {
            if(count.find(x)==count.end())
                count[x]=1;
            else
                count[x]=count[x]+1;
        }

        for(const pair<int, int> p: count) {
            if(m.find(p.second)!=m.end())
                return false;
            m[p.second]=true;
        }
        return true;
    }
};