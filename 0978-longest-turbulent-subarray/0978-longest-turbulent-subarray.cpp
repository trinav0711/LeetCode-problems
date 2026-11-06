class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        pair<int,int> prev, cur;
        prev={1,1};
        int ans=1;
        for(int i=1;i<arr.size();++i) {
            cur.first=cur.second=1;
            if(arr[i]>arr[i-1])
                cur.first=prev.second+1;
            else if(arr[i]<arr[i-1])
                cur.second=prev.first+1;
            ans=max({ans, cur.first, cur.second});
            prev.first=cur.first; prev.second=cur.second;
        }
        return ans;
    }
};