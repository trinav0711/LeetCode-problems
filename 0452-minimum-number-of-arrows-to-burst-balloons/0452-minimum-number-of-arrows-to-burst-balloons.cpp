class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> p;
        for(vector<int>v:points)
            p.push_back({v[0],v[1]});
        sort(p.begin(),p.end());
        int end=p[0].second, ar=1;
        for(int i=1;i<p.size();i++){
            if(p[i].first<=end)
                end=min(end, p[i].second);
            else{
                ar++;
                end=p[i].second;
            }
        }
        return ar;
    }
};