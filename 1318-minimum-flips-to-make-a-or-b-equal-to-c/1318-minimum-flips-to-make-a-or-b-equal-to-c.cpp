class Solution {
public:
    int minFlips(int a, int b, int c) {
        int m=max(a,max(b,c));
        int ans=0;
        while(m) {
            if(c&1) {
                if(!((a&1)|(b&1)))
                    ++ans;
            }
            else {
                if(a&1)
                    ++ans;
                if(b&1)
                    ++ans;
            }
            m>>=1;
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};