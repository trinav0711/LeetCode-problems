class Solution {
private:
    int ans;
    void bt(vector<int>& nums, vector<int>& v, int idx) {
        if(idx>=nums.size()) {
            int cur=0;
            for(int x:v)
                cur^=x;
            ans+=cur;
            return;
        }
        bt(nums, v, idx+1);
        v.push_back(nums[idx]);
        bt(nums, v, idx+1);
        v.pop_back();
    }
public:
    int subsetXORSum(vector<int>& nums) {
        ans=0;
        vector<int> v;
        bt(nums, v, 0);
        return ans;
    }
};