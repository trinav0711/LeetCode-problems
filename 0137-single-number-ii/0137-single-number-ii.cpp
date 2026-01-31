class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<bool> ans;
        ans.reserve(32);
        for(int i=0;i<32;i++) {
            int sum=0;
            for(int num:nums) {
                if((num>>i)&1)
                    sum++;
            }
            if(sum%3)
                ans[i]=1;
            else
                ans[i]=0;
        }
        long cur=1;
        long sum=0;
        for(int i=0;i<32;i++) {
            sum=sum+cur*ans[i];
            cur*=2;
        }
        return sum;
    }
};