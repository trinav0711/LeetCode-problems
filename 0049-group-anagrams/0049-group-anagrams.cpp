class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> v(strs);
        for(int i=0;i<v.size();i++)
            sort(v[i].begin(), v[i].end());
        unordered_map<string, vector<int>> m;
        for(int i=0;i<v.size();i++){
            if(m.find(v[i])==m.end())
                m[v[i]]={i};
            else
                m[v[i]].push_back(i);
        }
        v.clear();
        vector<vector<string>> ans;
        for(auto it=m.begin(); it!=m.end(); it++){
            vector<string> idx;
            for(auto x:it->second)
                idx.push_back(strs[x]);
            ans.push_back(idx);
        }
        return ans;
    }
};