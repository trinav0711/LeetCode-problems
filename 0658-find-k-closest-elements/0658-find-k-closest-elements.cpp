class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp=[](const pair<int,int>& a, const pair<int,int>& b) {
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;
        for(int n:arr) {
            pq.push({abs(n-x), n});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};