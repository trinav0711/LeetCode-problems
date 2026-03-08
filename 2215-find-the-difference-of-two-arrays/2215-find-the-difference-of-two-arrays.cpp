class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m {};
        for(int x:nums1) 
            m[x]=1;
        for(int x:nums2) {
            if(m.find(x)!=m.end() && m[x]==1) 
                m[x]=0;
            else if(m.find(x)==m.end())
                m[x]=2;
        }
        vector<vector<int>> v {{}, {}};
        for(const pair<int, int> p: m) {
            cout<<p.first<< " "<<p.second<<endl;
            if(p.second==1)
                v[0].push_back(p.first);
            else if(p.second==2)
                v[1].push_back(p.first);
        }
        return v;
    }
};