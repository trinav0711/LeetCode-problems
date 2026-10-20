class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int,int> s;
        for(const int x:people)
            ++s[x];
        int ans=0;
        while(!s.empty()) {
            ++ans;
            int first=s.begin()->first;
            int target=limit-first;
            --s[first];
            if(!s[first])
                s.erase(s.begin());
            if(s.empty()) break;
            auto itr=s.upper_bound(target);
            if(itr==s.begin()) {
                for(auto p:s)
                    ans+=p.second;
                break;
            }
            --itr;
            --(itr->second);
            if(!(itr->second))
                s.erase(itr);
        }
        return ans;
    }
};