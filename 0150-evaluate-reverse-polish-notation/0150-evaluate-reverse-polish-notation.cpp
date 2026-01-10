class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string tmp:tokens){
            if((tmp!="+")&&(tmp!="-")&&(tmp!="*")&&(tmp!="/"))
                s.push(stoi(tmp));
            else{
                int x=s.top();
                s.pop();
                if(tmp=="+")
                    x=x+s.top();
                else if(tmp=="-")
                    x=s.top()-x;
                else if(tmp=="*")
                    x=x*s.top();
                else
                    x=s.top()/x;
                s.pop();
                s.push(x);
            }
        }
        return s.top();
    }
};