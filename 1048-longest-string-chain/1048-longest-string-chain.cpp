class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> visit(words.size(),-1);
        sort(words.begin(),words.end(), [](const string& a, const string& b) {
            return a.size()<b.size();
        });
        unordered_map<int,vector<int>> m;
        for(int i=0;i<words.size();++i) {
            for(int j=i+1;j<words.size();++j) {
                if(words[i].length()!=words[j].length()-1)
                    continue;
                int i1=0,j1=0;
                while(i1<words[i].length() && j1<words[j].length()) {
                    if(words[i][i1]==words[j][j1]) ++i1;
                    ++j1;
                }
                if(i1>=words[i].length())
                    m[i].push_back(j);
            }
        }
        int ans=1;
        for(int i=0;i<words.size();++i) {
            if(visit[i]!=-1)
                continue;
            queue<int> q;
            q.push(i);
            visit[i]=1;
            int level=1;
            while(!q.empty()) {
                int sz=q.size();
                while(sz--) {
                    for(auto nei:m[q.front()]) {
                        if(visit[nei]<=level+1) {
                            visit[nei]=level+1;
                            q.push(nei);
                        }
                    }
                    q.pop();
                }
                ++level;
            }
        }
        return *max_element(visit.begin(), visit.end());
    }
};