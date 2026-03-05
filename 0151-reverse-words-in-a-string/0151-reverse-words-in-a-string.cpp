class Solution {
private:
    pair<string, int> findStr(string& str, int idx) {
        int i;
        for(i=idx;i<str.length() && str[i]!=' ';i++);
        return {str.substr(idx, i-idx), i};
    }
public:
    string reverseWords(string s) {
        vector<string> v;
        int i=0;
        while(i<s.length()) {
            for(i;i<s.length() && s[i]==' ';i++);
            if(i>=s.length())
                break;
            pair<string, int> tmp = findStr(s, i);
            v.push_back(tmp.first);
            i=tmp.second+1;
        }
        reverse(v.begin(), v.end());
        string ans=v[0];
        for(int i=1;i<v.size();i++)
            ans=ans+" "+v[i];
        return ans;
    }
};