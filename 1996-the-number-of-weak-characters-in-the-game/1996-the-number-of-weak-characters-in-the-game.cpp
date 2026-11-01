class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans=0;
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        for(int i=properties.size()-1, maxx=INT_MIN; i>=0; --i) {
            if(properties[i][1]<maxx) ++ans;
            maxx=max(maxx, properties[i][1]);
        }
        return ans;
    }
};