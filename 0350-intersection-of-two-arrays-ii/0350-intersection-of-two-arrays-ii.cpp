class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int,int>> m;
        for(int x:nums1) {
            if(m.find(x)==m.end())
                m.emplace(x, make_pair(1,0));
            else
                ++m[x].first;
        }
        for(int x:nums2) {
            if(m.find(x)!=m.end())
                ++m[x].second;
        }
        vector<int> ans;
        for(auto& [f,p]:m) {
            int count=min(p.first, p.second);
            while(count--)
                ans.push_back(f);
        }
        return ans;
    }
};