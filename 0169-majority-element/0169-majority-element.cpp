class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int max=0,maxIdx;
        for(auto x:nums){
            if(m.find(x)==m.end())
                m.emplace(x,1);
            else
                m[x]++;
        }
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(itr->second>max) {
                max=itr->second;
                maxIdx=itr->first;
            }
        }
        return maxIdx;
    }
};