class Solution {
public:
    int reverseBits(int n) {
        vector<bool> b;
        b.reserve(32);
        while(n) {
            b.push_back(n%2);
            n/=2;
        }
        while(b.size()<32)
            b.push_back(0);
        reverse(b.begin(), b.end());
        long cur=1;
        long sum=0;
        for(bool x:b){
            cout<<x;
            sum+=(x*cur);
            cur*=2;
        }
        return (int)sum;
    }
};