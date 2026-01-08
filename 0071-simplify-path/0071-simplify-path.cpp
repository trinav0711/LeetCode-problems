class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        if(path[0]!='/')
            return "";
        for(int i=1;i<path.size();i++){
            string tmp="";
            int j;
            for(j=i;j<path.size()&&path[j]!='/';j++)
                tmp+=path[j];
            if(tmp=="" && j<path.size()){
                i=j;
                continue;
            }
            if(tmp==".."){
                if(!s.empty())
                    s.pop();
            }
            else if(tmp!=".")
                s.push("/"+tmp);
            i=j;
        }
        string ans="";
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        if(ans=="")
            ans="/";
        return ans;
    }
};