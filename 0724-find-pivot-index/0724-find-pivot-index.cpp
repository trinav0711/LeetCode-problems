class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left, right;
        left.push_back(0);
        for(int i=1;i<nums.size();i++)
            left.push_back(left[i-1]+nums[i-1]);
        right.push_back(0);
        for(int i=1;i<nums.size();i++)
            right.push_back(right[i-1]+nums[nums.size()-i]);
        reverse(right.begin(), right.end());
        assert(left.size()==nums.size() && right.size()==nums.size());
        for(int i=0;i<nums.size();i++) {
            if(left[i]==right[i])
                return i;
        }
        return -1;
    }
};