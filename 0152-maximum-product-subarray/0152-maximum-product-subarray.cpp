class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double prefix = 0, suffix = 0; // double prevents intermediate overflow
        double ans = INT_MIN;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // Reset to 1 if we hit a zero in the previous step
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            
            // Multiply from left to right
            prefix *= nums[i];
            
            // Multiply from right to left
            suffix *= nums[n - 1 - i];
            
            // The max will either be in a prefix or a suffix
            ans = max({ans, prefix, suffix});
        }
        
        return static_cast<int>(ans);
    }
};