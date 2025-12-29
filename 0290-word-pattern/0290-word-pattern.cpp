class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string tmp="";
        for(char c:s){
            if(c==' '){
                v.push_back(tmp);
                tmp="";
            }
            else
                tmp+=c;
        }
        if(!tmp.empty())
            v.push_back(tmp);
        unordered_map<char, string> m1;
        if(v.size()!=pattern.length())
            return false;
        int i;
        for(i=0;i<v.size();i++){
            if(m1.find(pattern[i])==m1.end())
                m1.emplace(pattern[i], v[i]);
            else if(m1[pattern[i]]!=v[i])
                break;
        }
        if(i<v.size())
            return false;
        unordered_map<string, char> m2;
        for(i=0;i<v.size();i++){
            if(m2.find(v[i])==m2.end())
                m2.emplace(v[i], pattern[i]);
            else if(m2[v[i]]!=pattern[i])
                break;
        }
        return i==v.size();
    }
};