class Solution {
public:
    int lengthOfLastWord(string s) {
        int endIdx=s.size()-1;
        while(endIdx>=0 && s[endIdx]==' ') endIdx--;
        if(endIdx<0) return 0;
        int startIdx=endIdx-1;
        while(startIdx>=0 && s[startIdx]!=' ') startIdx--;
        if(startIdx<0) return endIdx+1;
        else return endIdx-startIdx;
    }
};