class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0, end=0, jumps=0;
        for(int i=0;i<nums.size();++i) {
            if(i==nums.size()-1) return jumps;
            reach=max(reach, i+nums[i]);
            if(i==end) {
                ++jumps;
                end=reach;
            }
        }
        return jumps;
    }
};