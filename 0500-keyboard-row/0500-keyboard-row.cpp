class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m;
        string str="qwertyuiop";
        for(char c:str) m[c]=0;
        str="asdfghjkl";
        for(char c:str) m[c]=1;
        str="zxcvbnm";
        for(char c:str) m[c]=2;
        vector<string> ans;
        for(string& str:words) {
            int i;
            for(i=1;i<str.length();++i) {
                if(m[tolower(str[i])]!=m[tolower(str[0])]) break;
            }
            if(i>=str.length()) ans.push_back(str);
        }
        return ans;
    }
};