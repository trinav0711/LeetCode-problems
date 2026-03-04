class Solution {
public:
    string reverseVowels(string s) {
        vector<int> pos; vector<char> v;
        set<char> vow = {'a','e','i', 'o', 'u'};
        for(int i=0;i<s.length();i++) {
            if(vow.find(std::tolower(s.at(i)))!=vow.end()) {
                pos.push_back(i);
                v.push_back(s.at(i));
            }
        }
        if(v.empty())
            return s;
        std::reverse(v.begin(), v.end());
        for(int i=0;i<pos.size();i++)
            s[pos[i]]=v[i];
        return s;
    }
};