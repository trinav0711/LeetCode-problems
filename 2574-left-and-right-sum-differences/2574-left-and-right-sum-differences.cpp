class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left, right;
        left.push_back(0);
        for(int i=1;i<nums.size();++i) left.push_back(left.back()+nums[i-1]);
        right.push_back(0);
        for(int i=nums.size()-2;i>=0;--i) right.push_back(right.back()+nums[i+1]);
        reverse(right.begin(), right.end());
        for(int i=0;i<nums.size();++i) left[i]=abs(left[i]-right[i]);
        return left;
    }
};