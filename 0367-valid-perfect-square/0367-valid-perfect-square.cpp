class Solution {
public:
    bool isPerfectSquare(int num) {
        long newnum=long(num), i;
        for(i=1;i*i<newnum;++i);
        return i*i==newnum;
    }
};