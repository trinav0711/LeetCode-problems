class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        vector<bool> d1, d2;
        for(int i=0;i<32;i++) {
            d1.push_back((left>>i)&1);
            d2.push_back((right>>i)&1);
        }
        reverse(d1.begin(), d1.end());
        reverse(d2.begin(), d2.end());
        int cur=0;
        for(cur;cur<32;cur++) {
            if((d1[cur]|d2[cur])&(d1[cur]^d2[cur]))
                break;
            else
                d1[cur]=d1[cur]&d2[cur];
        }
        if(cur<32) {
            for(cur;cur<32;cur++)
                d1[cur]=0;
        }
        cur=0;
        for(int i=0;i<32;i++) {
            cur<<=1;
            cur=cur|d1[i];
        }
        return cur;
    }
};