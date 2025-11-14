class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3){
            return nums.size();
        }
        int count=1,start=2,end=3,last_num=nums[1];
        int k=2;
        if(nums[1]==nums[0]) count++;
        while(start<nums.size()){
            if(nums[start]==last_num){
                if(count<2){
                    nums[k]=nums[start];
                    count++; start++; k++;
                    continue;
                }
                // Take action.
                for(end=start+1;end<nums.size();end++){
                    if(nums[end]!=last_num) break;
                }
                if(end>=nums.size()){
                    break;
                }
                nums[k]=last_num=nums[end];
                count=1;
                start=end+1;
                k++;
                continue;
            }
            else{
                nums[k]=nums[start];
                count=1;
                last_num=nums[start];
            }
            start++;
            k++;
        }
        return k;
    }
};