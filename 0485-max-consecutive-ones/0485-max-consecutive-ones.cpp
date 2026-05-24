class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev=0, ans=0, ctr=0;
        for(int x:nums) {
            if(x!=prev) {
                prev=x;
                ans=max(ans, ctr);
                ctr=0;
            }
            if(x) ++ctr; 
        }
        ans=max(ans, ctr);
        return ans;
    }
};