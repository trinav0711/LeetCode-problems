class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> m; vector<int> v1,v2;
        set<char> s1,s2;
        for(char c:word1) {
            if(m.find(c)==m.end())
                m[c]=1;
            else
                ++m[c];
            s1.insert(c);
        }
        for(auto& p:m)
            v1.push_back(p.second);
        m.clear();
        for(char c:word2) {
            if(m.find(c)==m.end())
                m[c]=1;
            else
                ++m[c];
            s2.insert(c);
        }
        if(s1.size()!=s2.size())
            return false;
        for(auto& p:m)
            v2.push_back(p.second);
        m.clear();
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i=0;i<v1.size();++i)
            if(v1[i]!=v2[i])
                return false;
        for(char c:s1)
            if(s2.find(c)==s2.end())
                return false;
        return true;
    }
};