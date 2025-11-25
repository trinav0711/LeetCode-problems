class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start=0, end=1;
        while(end<s.length()) {
            while(end < s.length() && s[end] != ' ') end++;
            int temp_end=end;
            end--;
            while(start < end) {
                swap(s[start], s[end]);
                start++; end--;
            }
            start=temp_end+1;
            end=start+1;
        }
        vector<bool> temp(s.length(), false);
        bool isSpace=true;
        for(int i=0;i<s.length();i++){
            if(s[i] != ' ') isSpace=false;
            if(s[i] == ' '){
                if(isSpace) temp[i]=true;
                else isSpace=true;
            }
        }
        int i=s.length()-1;
        while(i>=0 && s[i]==' ') i--;
        for(i=i+1;i<s.length();i++) temp[i]=true;
        string s1="";
        for(int i=0;i<s.length();i++){
            if(!temp[i]) s1+=s[i];
        }
        return s1;
    }
};