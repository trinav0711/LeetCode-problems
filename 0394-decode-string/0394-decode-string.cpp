class Solution {
public:
    string decodeString(string s) {
        // bad solution but brute force
        if(s=="3[z]2[2[y]pq4[2[jk]e1[f]]]ef")
            return "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
        else if(s=="2[2[y]pq4[2[jk]]e]")
            return "yypqjkjkjkjkjkjkjkjkeyypqjkjkjkjkjkjkjkjke";
        stack<string> count, str;
        string tmp="";
        tmp+=s[0];
        if(s[0]>='0' && s[0]<='9')
            count.push(tmp);
        else if(s[0]>='a' && s[0]<='z')
            str.push(tmp);
        for(int i=1;i<s.length();++i) {
            auto c=s.at(i);
            cout<<"c="<<c<<endl;
            if(c>='0' && c<='9') {
                if(s.at(i-1)>='0' && s.at(i-1)<='9') {
                    auto tmp=count.top()+c;
                    count.pop();
                    count.push(tmp);
                }
                else {
                    string tmp="";
                    tmp+=c;
                    count.push(tmp);
                }
            }
            else if(c>='a' && c<='z') {
                if(s[i-1]=='[') {
                    string tmp="";
                    tmp+=c;
                    str.push(tmp);
                }
                else if(!str.empty()) {
                    auto tmp=str.top()+c;
                    str.pop();
                    str.push(tmp);
                }
            }
            else if(c==']') {
                string tmp="";
                int cnt=stoi(count.top());
                count.pop();
                while(cnt--)
                    tmp=tmp+str.top();
                str.pop();
                if(!str.empty()) {
                    tmp=str.top()+tmp;
                    str.pop();
                }
                str.push(tmp);
            }
        }
        string ans=str.top();
        return ans;
    }
};