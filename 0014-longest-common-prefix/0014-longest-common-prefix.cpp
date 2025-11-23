class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int longest=0,i; char c;
        if(strs.empty()) return "";
        while(longest>=0){
            if(longest>=strs[0].size()) break;
            c=strs[0][longest];
            for(i=1;i<strs.size();i++){
                if(longest>=strs[i].size() || strs[i][longest]!=c)
                    break;
            }
            if(i<strs.size())
                break;
            else
                longest++;
        }
        return longest>0? strs[0].substr(0,longest):"";
    }
};