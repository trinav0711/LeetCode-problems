class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]].push_back(i);
        for(auto itr=m.begin();itr!=m.end();itr++){
            auto it=itr->second.begin();
            auto prev=it;
            for(it++;it!=itr->second.end();it++, prev++){
                if(*it-*prev<=k)
                    return true;
            }
        }
        return false;
    }
};