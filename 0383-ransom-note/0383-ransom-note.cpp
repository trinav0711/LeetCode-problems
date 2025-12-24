class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(char c:magazine){
            if(m.find(c)==m.end())
                m.emplace(c,1);
            else
                m[c]++;
        }
        bool exists=true;
        for(char c:ransomNote){
            if(m.find(c)==m.end() || m[c]==0){
                exists=false;
                break;
            }
            else
                m[c]--;
        }
        return exists;
    }
};