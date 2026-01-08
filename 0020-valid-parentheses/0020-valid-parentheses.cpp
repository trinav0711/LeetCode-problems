class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        int i;
        for(i=0;i<s.size();i++){
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{')){
                c.push(s[i]);
            }
            else if(c.empty())
                break;
            else{
                if((c.top()=='(' && s[i]==')')||(c.top()=='{' && s[i]=='}')||(c.top()=='[' && s[i]==']'))
                    c.pop();
                else
                    break;
            }
        }
        return i==s.size() && c.empty();
    }
};