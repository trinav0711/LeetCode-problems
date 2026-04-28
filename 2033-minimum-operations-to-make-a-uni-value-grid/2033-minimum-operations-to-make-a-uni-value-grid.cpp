class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(auto& v1: grid)
            for(auto x:v1)
                v.push_back(x);
        sort(v.begin(), v.end());
        for(int i=1;i<v.size();++i) {
            if((v[i]-v[i-1])%x)
                return -1;
        }
        int ans=0;
        for(int i=0;i<v.size();++i)
            ans+=((abs(v[i]-v[v.size()/2]))/x);
        return ans;
    }
};