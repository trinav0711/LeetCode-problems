class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0, left=0, right=height.size()-1;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>maxleft)
                    maxleft=height[left];
                else
                    sum=sum+maxleft-height[left];
                left++;
            }
            else {
                if(height[right]>maxright)
                    maxright=height[right];
                else
                    sum=sum+maxright-height[right];
                right--;
            }
        }
        return sum;
    }
};