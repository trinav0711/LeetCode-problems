class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx1, idx2;
        idx1=idx2=0;
        while(idx1<s.length() && idx2<t.length()) {
            for(idx2;idx2<t.length() && t.at(idx2)!=s.at(idx1);idx2++);
            if(idx2>=t.length())
                break;
            idx1++;
            idx2++;
        }
        return idx1>=s.length();
    }
};