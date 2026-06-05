class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int first=candidates-1, end=costs.size()-candidates;
        long long ans=0;
        struct Str {
            Str() {}
            bool operator()(pair<int,int>&x, pair<int,int>&y) {
                if(x.first==y.first) return x.second>y.second;
                return x.first>y.first;
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, Str> pq1, pq2;
        for(int i=0;i<=first;++i) pq1.push({costs[i], i});
        for(int i=max(first+1, end);i<costs.size();++i) pq2.push({costs[i], i});
        cout<<pq1.size()<< " "<<pq2.size()<<endl;
        while(k--) {
            if(pq2.empty() || (!pq1.empty() && pq1.top().first<=pq2.top().first)) {
                ans+=(pq1.top().first);
                cout<<"chose first "<<pq1.top().first<<" "<<pq1.top().second<<endl;
                pq1.pop();
                if(first+1<end) {
                    cout<<"added first"<<endl;
                    pq1.push({costs[first+1], first+1});
                    first++;
                }
            }
            else {
                ans+=(pq2.top().first);
                cout<<"chose second "<<pq2.top().first<<" "<<pq2.top().second<<endl;
                pq2.pop();
                if(end-1>first) {
                    cout<<"added second\n";
                    pq2.push({costs[end-1], end-1});
                    --end;
                }
            }
        }
        return ans;
    }
};