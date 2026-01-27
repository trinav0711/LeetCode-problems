class Solution {
public:
    int hammingWeight(int n) {
        int ctr=0;
        while(n) {
            if(n&1)
                ctr++;
            n>>=1;
        }
        return ctr;
    }
};