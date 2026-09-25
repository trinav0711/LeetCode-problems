class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int i;
        vector<int> ans; ans.reserve(nums.size()-k+1);
        for(i=0;i<nums.size()&&i<k;++i)
            pq.push({nums[i],i});
        ans.push_back(pq.top().first);
        for(i;i<nums.size();++i) {
            pq.push({nums[i], i});
            while(pq.top().second<=i-k)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};