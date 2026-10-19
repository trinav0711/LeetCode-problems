class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(1000, 0);
        vector<bool> out(1000, false);
        for(const auto& v:trust) {
            ++in[v[1]-1];
            out[v[0]-1]=true;
        }
        for(int i=0;i<1000;++i) {
            if(!out[i] && in[i]==n-1) {
                return i+1;
            }
        }
        return -1;
    }
};