class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()<1)
            return {};
        string tmp=to_string(nums[0])+"->";
        int start=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)
                continue;
            if(i==start+1)
                ans.push_back(to_string(nums[i-1]));
            else
                ans.push_back(tmp+to_string(nums[i-1]));
            start=i;
            tmp=to_string(nums[i])+"->";
        }
        if(start==nums.size()-1)
            ans.push_back(to_string(nums[start]));
        else
            ans.push_back(tmp+to_string(nums[nums.size()-1]));
        return ans;
    }
};