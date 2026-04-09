class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[1]<b[1];
        });
        int ans=1;
        for(int cur=points[0][1], i=1;i<points.size();++i) {
            if(points[i][0]>cur) {
                ++ans;
                cur=points[i][1];
            }
        }
        return ans;
    }
};