class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x:nums) ++freq[x];
        auto cmp=[&](const int& a,const int& b) {
            return freq[a]>freq[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto& p:freq) {
            pq.push(p.first);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};