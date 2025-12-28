class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        int i;
        for(i=0;i<s.length();i++){
            if(m.find(s[i])==m.end())
                m[s[i]]=t[i];
            else if(m[s[i]]!=t[i])
                break;
        }
        if(i<s.length())
            return false;
        m.clear();
        for(i=0;i<t.length();i++){
            if(m.find(t[i])==m.end())
                m[t[i]]=s[i];
            else if(m[t[i]]!=s[i])
                break;
        }
        return i>=s.length();
    }
};