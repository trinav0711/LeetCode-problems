class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector prev{1};
        for(int i=1;i<=rowIndex;++i) {
            vector<int> cur(i+1, 1);
            for(int idx=1;idx<i;++idx)
                cur[idx]=prev[idx-1]+prev[idx];
            if(i==rowIndex)
                return cur;
            prev.clear();
            for(int x:cur)
                prev.push_back(x);
        }
        return prev;
    }
};