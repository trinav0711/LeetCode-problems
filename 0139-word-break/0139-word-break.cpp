class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> m;
        for(string str:wordDict)
            m[str]=true;
        vector<bool> dp;
        dp.reserve(s.length());
        for(int i=0;i<s.length();i++) {
            dp.push_back(false);
            if(m.find(s.substr(0,i+1))!=m.end()) {
                dp[i]=true;
                continue;
            }
            for(int j=0;j<i;j++) {
                if(dp[j] && m.find(s.substr(j+1, i-j))!=m.end()) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()-1];
    }
};