class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> m;
        for(int i=0;i<s.length();++i)
            m[s[i]]=i;
        int i=0;
        while(i<s.length()) {
            int maxidx=m[s[i]], start=i;
            for(int j=i+1;j<maxidx;++j) {
                maxidx=max(maxidx, m[s[j]]);
            }
            ans.push_back(abs(maxidx-start+1));
            i=maxidx+1;
        }
        return ans;
    }
};