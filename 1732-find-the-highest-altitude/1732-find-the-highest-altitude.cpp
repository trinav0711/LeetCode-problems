class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur=0, m=0;
        for(int x:gain) {
            cur=cur+x;
            m=max(m, cur);
        }
        return m;
    }
};