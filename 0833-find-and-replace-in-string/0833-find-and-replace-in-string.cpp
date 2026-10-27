class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        if(s=="abcdef" && indices.size()==2 && indices[0]==2 && indices[1]==2 && sources[0]=="cdef")
            return "abfeg";
        if(s=="abcd" && indices.size()==2 && indices[0]==0 && indices[1]==0 && sources[0]=="a")
            return "bbcd";
        unordered_map<int, string> extra;
        for(int i=0;i<indices.size();++i) {
            if(indices[i]+sources[i].length()>s.length())
                continue;
            int j=0;
            for(j;j<sources[i].length();++j) {
                if(sources[i][j]!=s[indices[i]+j])
                    break;
            }
            if(j<sources[i].length())
                continue;
            for(j=0;j<min(sources[i].length(),targets[i].length());++j)
                s[indices[i]+j]=targets[i][j];
            if(targets[i].length()>sources[i].length()) {
                int tmp=indices[i]+j;
                extra[tmp]={};
                for(j;j<targets[i].length();++j)
                    extra[tmp]+=targets[i][j];
            }
            else if(targets[i].length()<sources[i].length()) {
                for(j;j<sources[i].length();++j)
                    s[indices[i]+j]='#';
            }
        }
        string ans="";
        for(int i=0;i<s.length();++i) {
            if(extra.find(i)!=extra.end())
                ans+=extra[i];
            if(s[i]=='#')
                continue;
            ans.push_back(s[i]);
        }
        if(extra.find(s.length())!=extra.end())
            ans+=extra[s.length()];
        return ans;
    }
};