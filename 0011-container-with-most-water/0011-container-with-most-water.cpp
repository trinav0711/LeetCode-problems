class Solution {
public:
    int maxArea(vector<int>& height) {
        int first=0, last=height.size()-1, maxarea;
        maxarea=(last-first)*min(height[first], height[last]);
        while(first < last){
            if(height[first] < height[last])
                first++;
            else
                last--;
            maxarea=max(maxarea, min(height[first], height[last])*(last-first));
        }
        return maxarea;
    }
};