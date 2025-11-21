class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        int sum=0, prevsum=0;
        for(int i=0;i<s.size();){
            if(s[i]=='I'){
                if(i+1<s.size()){
                    if(s[i+1]=='V') sum+=4;
                    else if(s[i+1]=='X') sum+=9;
                }
            }
            else if(s[i]=='X'){
                if(i+1<s.size()){
                    if(s[i+1]=='L') sum+=40;
                    else if(s[i+1]=='C') sum+=90;
                }
            }
            else if(s[i]=='C'){
                if(i+1<s.size()){
                    if(s[i+1]=='D') sum+=400;
                    else if(s[i+1]=='M') sum+=900;
                }
            }
            if(sum>prevsum) i+=2;
            else{
                sum+=m[s[i]]; i++;
            }
            prevsum=sum;
        }
        return sum;
    }
};