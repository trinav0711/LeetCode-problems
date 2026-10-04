class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> v;
        for(int i=0;i<position.size();++i)
            v.push_back({position[i], static_cast<double>(target-position[i])/static_cast<double>(speed[i])});
        sort(v.begin(), v.end());
        int ans=1; double low=v.back().second;
        for(int i=v.size()-2;i>=0;--i) {
            if(v[i].second>low) {
                ++ans;
                low=v[i].second;
            }
        }
        return ans;
    }
};