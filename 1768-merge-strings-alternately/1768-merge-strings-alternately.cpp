class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int m=min(word1.length(), word2.length());
        for(int i=0;i<m;i++)
            s=s+word1.at(i)+word2.at(i);
        if(word1.length()>word2.length()) {
            for(int i=m;i<word1.length();i++)
                s+=word1.at(i);
        }
        else {
            for(int i=m;i<word2.length();i++)
                s+=word2.at(i);
        }
        return s;
    }
};