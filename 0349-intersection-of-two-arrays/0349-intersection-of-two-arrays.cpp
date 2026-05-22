class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> visit; vector<int> ans;
        for(int x:nums1)
            visit.insert(x);
        for(int x:nums2) {
            if(visit.find(x)!=visit.end()) {
                ans.push_back(x);
                visit.erase(x);
            }
        }
        return ans;
    }
};