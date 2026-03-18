class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0, end=height.size()-1;
        int m=INT_MIN;
        while(start<end) {
            m=max(m, min(height[start], height[end])*(end-start));
            if(height[start]<height[end])
                ++start;
            else
                --end;
        }
        return m;
    }
};