class Solution {
private:
    unordered_map<string, int> m;
    int bt(string& str, int idx) {
        if(str.empty())
            return 1;
        if(idx<0)
            return 0;
        if(m.find(str)!=m.end())
            return m[str];
        char c1=str.back(); str.pop_back();
        int first=0, second=0;
        if(idx) {
            char c2=str.back(); str.pop_back();
            if(c2=='1' || (c2=='2' && c1<='6')) 
                first=bt(str, idx-2);
            str.push_back(c2);
        }
        if(c1!='0')
            second=bt(str, idx-1);
        str.push_back(c1);
        m[str]=first+second;
        return m[str];
    }
public:
    int numDecodings(string s) {
        return bt(s, s.length()-1);
    }
};