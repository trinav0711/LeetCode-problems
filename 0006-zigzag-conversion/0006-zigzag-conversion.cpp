class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ss(numRows, "");
        bool zigzag = false; int curIdx=0;
        for(char c : s){
            if(!zigzag){
                ss[curIdx]+=c;
                curIdx++;
                if(curIdx>=numRows){
                    curIdx=max(0, numRows-2);
                    zigzag=true;
                }
            }
            else{
                ss[curIdx]+=c;
                curIdx--;
                if(curIdx<0){
                    curIdx=1;
                    if(numRows==1) curIdx=0;
                    zigzag=false;
                }
            }
        }
        string s1="";
        for(string temp:ss) s1+=temp;
        return s1;
    }
};