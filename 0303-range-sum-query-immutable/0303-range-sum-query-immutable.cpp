class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();++i)
            prefix.push_back(prefix.back()+nums[i]);
    }
    
    int sumRange(int left, int right) {
        return prefix[right]-(left?prefix[left-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */