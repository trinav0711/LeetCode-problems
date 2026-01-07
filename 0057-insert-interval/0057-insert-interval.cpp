class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.empty())
            return {newInterval};
        int start=0;
        for(start;start<intervals.size();start++)
            if(intervals[start][1]>=newInterval[0])
                break;
        if(start>=intervals.size()){
            intervals.push_back({newInterval[0], newInterval[1]});
            return intervals;
        }
        else if(newInterval[1]<intervals[start][0]){
            for(int i=0;i<start;i++)
                ans.push_back(intervals[i]);
            ans.push_back(newInterval);
            for(int i=start;i<intervals.size();i++)
                ans.push_back(intervals[i]);
            return ans;
        }
        for(int i=0;i<start;i++)
            ans.push_back({intervals[i][0], intervals[i][1]});
        if(start<intervals.size()-1){
            if(newInterval[1]<intervals[start+1][0])
                ans.push_back({min(intervals[start][0],newInterval[0]), max(newInterval[1], intervals[start][1])});
            else{
                int i;
                for(i=start+1;i<intervals.size() && intervals[i][0]<=newInterval[1];i++);
                ans.push_back({min(intervals[start][0],newInterval[0]), max(intervals[i-1][1],newInterval[1])});
                start=i-1;
            }
            for(start=start+1;start<intervals.size();start++)
                ans.push_back({intervals[start][0], intervals[start][1]});
        }
        else {
            ans.push_back({min(intervals[start][0],newInterval[0]), max(newInterval[1], intervals[start][1])});
        }
        return ans;
    }
};