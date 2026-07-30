class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i,j;
        for(i=0,j=0;i<nums1.size()&&j<nums2.size();) {
            if(nums1[i]<=nums2[j])
                merge.push_back(nums1[i++]);
            else
                merge.push_back(nums2[j++]);
        }
        if(i<nums1.size()) {
            for(i;i<nums1.size();++i) merge.push_back(nums1[i]);
        }
        else if(j<nums2.size()) {
            for(j;j<nums2.size();++j) merge.push_back(nums2[j]);
        }
        return merge.size()%2?merge[merge.size()/2]:((double(merge[merge.size()/2]+merge[merge.size()/2-1]))/2);
    }
};