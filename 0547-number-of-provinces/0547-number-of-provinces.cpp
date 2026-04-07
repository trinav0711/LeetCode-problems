class Solution {
private:
    void dfs(int source, unordered_set<int>& s, vector<vector<int>>& v) {
        s.erase(source);
        cout<<"At "<<source<<endl;
        for(int i=0;i<v[source].size();++i){
            if(v[source][i] && s.contains(i))
                dfs(i, s, v);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        unordered_set<int> s;
        for(int i=0;i<isConnected.size();++i)
            s.insert(i);
        while(!s.empty()) {
            ++ans;
            cout<<"Starting with "<<*s.begin()<<endl;
            dfs(*s.begin(), s, isConnected);
        }
        return ans;
    }
};