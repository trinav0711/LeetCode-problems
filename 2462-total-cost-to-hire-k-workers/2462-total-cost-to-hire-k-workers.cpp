class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        int i=0, j=n-1;
        priority_queue<int, vector<int>, greater<int>> f,l;
        for(;i<candidates;++i)
            f.push(costs[i]);
        while(j>=i && j>=n-candidates)
            l.push(costs[j--]);
        long long ans=0;
        while(k--) {
            int ans1=(f.empty())?INT_MAX:f.top();
            int ans2=(l.empty())?INT_MAX:l.top();
            if(ans1<=ans2) {
                ans+=f.top();
                f.pop();
                if(i<=j)
                    f.push(costs[i++]);
            }
            else {
                ans+=l.top();
                l.pop();
                if(j>=i)
                    l.push(costs[j--]);
            }
        }
        return ans;
    }
};