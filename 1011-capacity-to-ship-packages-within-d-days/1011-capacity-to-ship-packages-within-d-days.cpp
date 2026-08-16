class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(), weights.end()), right=accumulate(weights.begin(), weights.end(), 0);
        while(left<right) {
            int mid=(left+right)/2;
            int sum=0, segs=1;
            for(int x:weights) {
                if(x+sum>mid) {
                    sum=x; ++segs;
                }
                else sum+=x;
            }
            if(segs>days) left=mid+1;
            else right=mid;
        }
        return left;
    }
};