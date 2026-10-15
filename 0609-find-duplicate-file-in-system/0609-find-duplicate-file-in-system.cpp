class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(const string& str:paths) {
            int i;
            for(i=0;i<str.length() && str[i]!=' ';++i);
            string path=str.substr(0, i);
            for(++i;i<str.length();) {
                int j;
                string name, content;
                for(j=i;j<str.length() && str[j]!='(';++j);
                if(j>=str.length()) break;
                name=str.substr(i, j-i);
                int start=++j;
                for(j;j<str.length() && str[j]!=')';++j);
                if(j>=str.length()) break;
                content=str.substr(start, j-start);
                m[content].push_back(path+"/"+name);
                i=j+1;
                while(i<str.length() && str[i]==' ') ++i;
            }
        }
        for(auto& [content, v]:m) {
            if(v.size()==1)
                continue;
            vector<string> tmp;
            for(auto& str:v)
                tmp.push_back(str);
            ans.push_back(tmp);
        }
        return ans;
    }
};