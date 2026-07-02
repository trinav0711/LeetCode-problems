class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> sm, pm;
        if(s.length()<p.length()) return {};
        for(char c:p) pm[c]++;
        for(int start=0;start<p.length();++start) {
            sm[s[start]]++;
        }
        int same=0;
        for(auto& p:pm) {
            if(pm[p.first]==sm[p.first]) ++same;
        }  
        vector<int> ans;
        if(pm.size()==sm.size() && same==pm.size()) ans.push_back(0);
        for(int i=1;i<=s.length()-p.length();++i) {
            char prev=s[i-1], next=s[i+p.length()-1];
            sm[prev]--; sm[next]++;
            if(sm[prev]==0) sm.erase(prev);
            if(sm.size()!=pm.size())
                continue;
            same=0;
            for(auto&p:pm) {
                if(pm[p.first]==sm[p.first]) ++same;
            }
            if(same==pm.size())
                ans.push_back(i);
        }
        return ans;
    }
};