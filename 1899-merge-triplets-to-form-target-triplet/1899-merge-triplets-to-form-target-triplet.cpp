class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        for(int cur=0;cur<3;++cur) {
            bool found=false;
            for(int i=0;i<triplets.size();++i) {
                if(target[cur]==triplets[i][cur]) {
                    int j;
                    for(j=0;j<3;++j) {
                        if(triplets[i][j]>target[j]) break;
                    }
                    if(j>=3) found=true;
                }
                if(found) break;
            }
            if(!found) return false;
        }
        return true;
    }
};