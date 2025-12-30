class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        if(t.length()!=s.length())
            return false;
        for(char c:s){
            if(m.find(c)==m.end())
                m[c]=1;
            else
                m[c]++;
        }
        for(char c:t){
            if(m.find(c)==m.end() || m[c]==0)
                return false;
            m[c]--;
        }
        return true;
    }
};