class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1]<b[1];
        });
        int ans=0;
        for(int i=1, prev=0;i<intervals.size();++i) {
            if(intervals[i][0]<intervals[prev][1])
                ++ans;
            else
                prev=i;
        }
        return ans;
    }
};