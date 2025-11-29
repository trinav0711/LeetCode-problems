class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line;
        int cur,cur_space;
        for(cur=0;cur<words.size();){
            cur_space=words[cur].size();
            int i=cur+1;
            for(i;i<words.size();i++){
                if(cur_space+1+words[i].size()>maxWidth)
                    break;
                cur_space+=(1+words[i].size());
            }
            i--;
            cout<<"i now at "<<i<<"\n";
            int padding=maxWidth-cur_space;
            string s=words[cur];
            if(i+1>=words.size() || i==cur){
                for(int j=cur+1;j<=i;j++){
                    s=s+" "; s=s+words[j];
                }
                for(int ctr=0;ctr<padding;ctr++) s+=" ";
            }
            else {
                int spaces=padding+i-cur;
                int common_space=spaces/(i-cur), extra_right=spaces%(i-cur);
                
                cout<<"spaces="<<spaces<<"\n";
                cout<<"common space="<<common_space<<"\n";
                cout<<"extra space="<<extra_right<<"\n";
                for(int j=cur+1, slots=0;j<=i;j++){
                    int spaceCount=common_space+(j-cur<=extra_right?1:0);
                    for(int ctr=0;ctr<spaceCount;ctr++) s+=" ";
                    s=s+words[j];
                }
            }
            line.push_back(s);
            cur=i+1;
            cout<<"Cur is now "<<cur<<"\n";
        }
        return line;
    }
};