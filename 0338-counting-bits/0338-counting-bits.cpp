class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        while(n) {
            ans[n]=0;
            int i=n;
            while(i) {
                if(i&1)
                    ++ans[n];
                i=i>>1;
            }
            --n;
        }
        return ans;
    }
};