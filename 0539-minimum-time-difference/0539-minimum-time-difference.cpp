class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>> v;
        for(const auto& str:timePoints) {
            v.push_back({stoi(str.substr(0,2)), stoi(str.substr(3,2))});
        }
        sort(v.begin(), v.end());
        int minn=INT_MAX;
        for(int i=0;i<v.size();++i) {
            int next=(i+1)%(v.size());
            int diff;
            if(v[next].first>v[i].first) {
                diff=60-v[i].second+v[next].second+60*(v[next].first-v[i].first-1);
            }
            else if(v[next].first==v[i].first) {
                diff=v[next].second-v[i].second;
            }
            else {
                diff=60-v[i].second+v[next].second+(24-v[i].first-1)*60+v[next].first*60;
            }
            diff=abs(diff);
            minn=min(minn, diff);
        }
        return minn;
    }
};