class Solution {
private:
    void dfs(vector<string>& ans, string cur, unordered_map<string, multiset<string>>& m) {
        // While there are still outgoing flights from 'cur'
        while (m.find(cur) != m.end() && !m[cur].empty()) {
            // Grab the lexicographically smallest destination
            string next = *m[cur].begin();
            
            // Erase ONLY ONE copy of the ticket using an iterator
            m[cur].erase(m[cur].begin());
            
            // Recursively visit the next airport
            dfs(ans, next, m);
        }
        
        // Add the airport to the itinerary ONLY after exploring all its outgoing flights
        ans.push_back(cur);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for(auto&& v:tickets) {
            m[v[0]].insert(v[1]);
        }
        vector<string> ans;
        dfs(ans, "JFK", m);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};