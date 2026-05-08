class Solution {
private:
    int t;
    int bs(vector<int>& v, int s, int e) {
        if(s>e)
            return -1;
        if(v[s]==t) return s;
        if(v[e]==t) return e;
        int mid=(s+e)/2;
        if(v[mid]==t)
            return mid;
        if(v[mid]>v[s]) {
            if(t<v[s] || t>v[mid])
                return bs(v, mid+1, e);
            return bs(v, s, mid-1);
        }
        else {
            if(t>v[s] || t<v[mid])
                return bs(v, s, mid-1);
        }
        return bs(v, mid+1, e);
    }
public:
    int search(vector<int>& nums, int target) {
        t=target;
        return bs(nums, 0, nums.size()-1);
    }
};