class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        auto func=[&points](const int i, const int j) {
            double x=static_cast<double>(points[i][0]), y=static_cast<double>(points[i][1]);
            double d1, d2;
            d1=x*x+y*y;
            x=static_cast<double>(points[j][0]); y=static_cast<double>(points[j][1]);
            d2=x*x+y*y;
            return d1<d2;
        };
        priority_queue<int, vector<int>, decltype(func)> pq(func);
        for(int i=0;i<points.size();++i) {
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()) {
            ans.push_back(points[pq.top()]);
            pq.pop();
        }
        return ans;
    }
};