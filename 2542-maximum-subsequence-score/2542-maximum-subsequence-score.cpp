class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        using ll=long long;
        vector<pair<int,int>>p;
        for(int i=0;i<nums1.size();++i)
            p.push_back({nums2[i], nums1[i]});
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        ll ans=-1, sum=0;
        for(auto& [f,s]: p) {
            pq.push(s);
            sum+=s;
            if(pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans=max(ans, f*sum);
        }
        return ans;
    }
};