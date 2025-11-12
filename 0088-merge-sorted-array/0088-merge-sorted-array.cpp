class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v; v.reserve(m+n);
        int i, j;
        for (i = 0, j = 0; i < m && j < n;) {
            if (nums1[i] <= nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        }
        if (i < m)
            for (i; i < m; i++)
                v.push_back(nums1[i]);
        else
            for (j; j < n; j++)
                v.push_back(nums2[j]);
        assert(v.size() == m + n);
        for (i = 0; i < m + n; i++)
            nums1[i] = v[i];
    }
};