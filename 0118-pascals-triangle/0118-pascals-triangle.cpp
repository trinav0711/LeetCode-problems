class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;++i) {
            vector<int> v(i+1, 1);
            for(int idx=1;idx<i;++idx)
                v[idx]=ans[i-1][idx-1]+ans[i-1][idx];
            ans.push_back(v);
        }
        return ans;
    }
};