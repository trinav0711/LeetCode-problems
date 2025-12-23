class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=1, end=1, ans=INT_MAX;
        vector<int>arr; arr.reserve(nums.size()+1);
        arr[0]=0;
        for(int i=1;i<=nums.size();i++)
            arr[i]=arr[i-1]+nums[i-1];
        while(start<=end && end<=nums.size()){
            if(arr[end]-arr[start-1] < target)
                end++;
            else{
                ans=min(ans, end-start+1);
                start++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};