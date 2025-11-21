class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()), suffix(nums.size()), result(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        for(int i=1;i<nums.size()-1;i++){
            result[i]=prefix[i-1]*suffix[i+1];
        }
        result[0]=suffix[1];
        result[nums.size()-1]=prefix[nums.size()-2];
        return result;
    }
};