class Solution {
public:
    string minWindow(string s, string t) {
        int need[256] = {0}, has[256] = {0};
        int n = s.size(), m = t.size(), idx = -1, best = INT_MAX;
        for(char x: t) need[x]++;
        for(int l = 0, r = 0, match =0; r < n; r++) {
            has[s[r]]++;
            if(need[s[r]] && has[s[r]] <= need[s[r]]) match++; 
            while(match == m) {
                int len = r - l +1;
                if(len < best) {
                    best = len;
                    idx = l;
                }
                has[s[l]]--;
                if(need[s[l]] && has[s[l]] < need[s[l]])
                    match--;
                l++;
            }
        }
        return idx != -1 ? s.substr(idx, best) : "";
    }
};