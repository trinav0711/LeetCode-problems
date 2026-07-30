class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=1;
        queue<string> q;
        unordered_set<string> m;
        for(auto& str:wordList) m.insert(str);
        if(m.find(endWord)==m.end()) return 0;
        q.push(beginWord);
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto& str=q.front();
                if(str==endWord) return ans;
                for(int idx=0;idx<str.length();++idx) {
                    char c=str[idx];
                    for(int i=0;i<26;++i) {
                        if(c-'a'==i) continue;
                        str[idx]=char('a'+i);
                        if(m.find(str)!=m.end()) {
                            if(str==endWord) return ans+1;
                            cout<<"pushed "<<str<<" and ans="<<ans<<endl;
                            q.push(str);
                            m.erase(str);
                        }
                        str[idx]=c;
                    }
                }
                q.pop();
            }
            ++ans;
            cout<<"ans="<<ans<<endl;
        }
        return 0;
    }
};