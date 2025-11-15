class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>v; v.reserve(nums.size());
        vector<int>v1(nums);
        for(int i=0;i<nums.size();i++){
            if(i+k<nums.size()) v.push_back(i+k);
            else v.push_back((i+k)%nums.size());
        }
        for(int i=0;i<v.size();i++)
            nums[v[i]]=v1[i];
    }
};