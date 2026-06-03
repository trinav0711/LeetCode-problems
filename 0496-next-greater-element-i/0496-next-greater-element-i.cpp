class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();++i) {
            if(m.find(nums2[i])==m.end())
                m[nums2[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();++i) {
            if(m.find(nums1[i])==m.end())
                ans.push_back(-1);
            else {
                int j=m[nums1[i]];
                for(++j;j<nums2.size();++j) {
                    if(nums2[j]>nums1[i]) {
                        ans.push_back(nums2[j]); break;
                    }
                }
                if(j>=nums2.size())
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};