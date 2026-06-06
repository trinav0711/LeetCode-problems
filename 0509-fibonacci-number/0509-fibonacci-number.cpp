class Solution {
public:
    int fib(int n) {
        if(!n) return 0;
        if(n==1) return 1;
        int tmp, prev=0, cur=1;
        while(--n) {
            tmp=prev+cur;
            prev=cur;
            cur=tmp;
        }
        return cur;
    }
};