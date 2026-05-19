class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visit;
        for(auto x:nums) {
            if(visit.find(x)!=visit.end())
                return true;
            visit.insert(x);
        }
        return false;
    }
};