class Solution {
private:
    int memo[1 << 18]; // Adjust size based on constraints (numSlots <= 9 means 18 bits)
    
    int dp(int idx, int mask, int numSlots, vector<int>& nums) {
        if (idx == nums.size()) return 0;
        if (memo[mask] != -1) return memo[mask];
        
        int max_val = 0;
        // Try placing nums[idx] into each available slot
        for (int slot = 1; slot <= numSlots; ++slot) {
            // Check how many items are currently in this slot using 2 bits per slot
            // Slot i uses bits: 2*(i-1) and 2*(i-1) + 1
            int slot_shift = 2 * (slot - 1);
            int count = (mask >> slot_shift) & 3; // Get current count (0, 1, or 2)
            
            if (count < 2) { // If slot has less than 2 items
                int next_mask = mask + (1 << slot_shift);
                int current_and = (nums[idx] & slot) + dp(idx + 1, next_mask, numSlots, nums);
                max_val = max(max_val, current_and);
            }
        }
        return memo[mask] = max_val;
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, numSlots, nums);
    }
};