class Solution {
public:
    int firstUniqChar(string s) {
        int idx=s.length();
        unordered_set<char> dup; unordered_map<char, int>m;
        for(int i=0;i<s.length();++i) {
            if(dup.find(s[i])!=dup.end())
                continue;
            if(m.find(s[i])!=m.end()) {
                dup.insert(s[i]);
                m.erase(s[i]);
            }
            else
                m[s[i]]=i;
        }
        for(auto [f,s]:m)
            idx=min(idx, s);
        return idx<s.length()?idx:-1;
    }
};