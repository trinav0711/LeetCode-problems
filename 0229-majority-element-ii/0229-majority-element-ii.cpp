class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        double cutoff=static_cast<double>(nums.size())/3.0;
        for(int x:nums)
            ++m[x];
        vector<int> ans;
        for(const auto& p:m) {
            if(static_cast<double>(p.second)>cutoff)
                ans.push_back(p.first);
        }
        return ans;
    }
};