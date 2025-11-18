class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> tmp(citations);
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        int i;
        for(i=0;i<tmp.size();i++){
            if(tmp[i]<i+1) break;
        }   
        return i;
    }
};