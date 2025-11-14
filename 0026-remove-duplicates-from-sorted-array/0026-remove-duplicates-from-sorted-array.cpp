class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniq=1; vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            uniq++;
            v.push_back(nums[i]);
        }
        nums=v;
        return uniq;
    }
};