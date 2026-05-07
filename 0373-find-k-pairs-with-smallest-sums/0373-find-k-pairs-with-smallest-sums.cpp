class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int x:nums1)
            pq.push({x+nums2[0], 0});
        vector<vector<int>> ans;
        while(k-- && !pq.empty()) {
            auto pos=pq.top().second;
            vector v{pq.top().first-nums2[pos], nums2[pos]};
            ans.push_back(v);
            if(pos<nums2.size()-1) {
                pq.push({pq.top().first-nums2[pos]+nums2[pos+1], pos+1});
            }
            pq.pop();
        }
        return ans;
    }
};