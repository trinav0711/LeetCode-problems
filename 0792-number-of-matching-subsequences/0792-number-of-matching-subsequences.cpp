class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, queue<pair<int,int>>> m;
        for(int i=0;i<words.size();++i) {
            m[words[i][0]].push({i,0});
        }
        int ans=0;
        for(const char c:s) {
            if(m.find(c)==m.end())
                continue;
            int sz=m[c].size();
            while(sz--) {
                auto [idx,cnt]=m[c].front(); m[c].pop();
                ++cnt;
                if(cnt>=words[idx].length())
                    ++ans;
                else
                    m[words[idx][cnt]].push({idx,cnt});
            }
        }
        return ans;
    }
};