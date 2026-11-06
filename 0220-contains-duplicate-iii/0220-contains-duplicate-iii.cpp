class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> s;
        int left=0, right=min(indexDiff, static_cast<int>(nums.size()-1));
        for(int i=0;i<=right;++i)
            s.insert(nums[i]);
        for(auto itr=next(s.begin());itr!=s.end();++itr) {
            auto bef=prev(itr);
            if(*itr-*bef <= valueDiff)
                return true;
        }
        while(right<nums.size()-1) {
            s.erase(s.find(nums[left++]));
            ++right;
            s.insert(nums[right]);
            auto itr=s.find(nums[right]);
            auto r=next(itr);
            if(r!=s.end() && *r-*itr <= valueDiff)
                return true;
            if(itr!=s.begin()) {
                r=prev(itr);
                if(*itr-*r <= valueDiff)
                    return true;
            }
        }
        return false;
    }
};