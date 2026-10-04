class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> q;
        for(int i=0;i<queries.size();++i)
            q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> ans(queries.size(), -1);
        for(int j=0, i=0;j<q.size();++j) {
            while(i<intervals.size() && intervals[i][0]<=q[j].first) {
                pq.push({intervals[i][1]-intervals[i][0]+1, intervals[i][1]});
                ++i;
            }
            while(!pq.empty() && pq.top().second<q[j].first)
                pq.pop();
            ans[q[j].second]=pq.empty()?-1:pq.top().first;
        }
        return ans;
    }
};