class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return 0;
        unordered_map<char, int> s1m, s2m;
        for(char c:s1)
            ++s1m[c];
        int start=0, end=s1.length()-1;
        while(end<s2.length()) {
            if(s2m.empty()) {
                for(int i=start;i<=end;++i)
                    ++s2m[s2[i]];
            }
            else {
                if(start) {
                    --s2m[s2[start-1]];
                    if(!s2m[s2[start-1]]) s2m.erase(s2[start-1]);
                }
                ++s2m[s2[end]];
            }
            bool same=true;
            for(auto& [c, cnt]:s1m) {
                if(s2m.find(c)==s2m.end() || cnt!=s2m[c]) {
                    same=false; break;
                }
            }
            if(same) return true;
            ++start; ++end;
        }
        return false;
    }
};