class Solution {
private:
    int getIdx(vector<int>& v, int s, int e) {
        if(v[s+1]<v[s]) {
            if(s==0 || v[s]>v[s-1])
                return s;
        }
        if(s==e)
            return -1;
        if(v[e]>v[e-1]) {
            if(e==v.size()-1 || v[e]>v[e+1])
                return e;
        }
        if(s>=e)
            return -1;
        int mid=(s+e)/2;
        if(v[mid]>v[mid+1] && (mid==0 || v[mid]>v[mid-1]))
            return mid;
        int idx= getIdx(v, s, mid);
        if(idx!=-1)
            return idx;
        return getIdx(v, mid+1, e);
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        return getIdx(nums, 0, nums.size()-1);
    }
};