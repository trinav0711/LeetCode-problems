class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jump(nums.size());
        jump[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0)
                jump[i]=1001;
            else{
                int minEle=jump[i+1];
                for(int j=i+2;j<=i+nums[i] && j<nums.size();j++)
                    minEle=min(minEle,jump[j]);
                jump[i]=1+minEle;
            }
        }
        return jump[0];
    }
};