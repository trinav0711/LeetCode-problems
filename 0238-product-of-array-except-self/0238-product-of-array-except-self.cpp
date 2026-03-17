class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        cin.tie(0); ios_base::sync_with_stdio(0);
        vector<int> pre, suf;
        pre.push_back(1);
        suf.push_back(1);
        for(int i=1;i<nums.size();i++)
            pre.push_back(pre[i-1]*nums[i-1]);
        reverse(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++)
            suf.push_back(suf[i-1]*nums[i-1]);
        reverse(nums.begin(), nums.end());
        reverse(suf.begin(), suf.end());
        for(int i=0;i<nums.size();i++)
            nums[i]=pre[i]*suf[i];
        return nums;
    }
};