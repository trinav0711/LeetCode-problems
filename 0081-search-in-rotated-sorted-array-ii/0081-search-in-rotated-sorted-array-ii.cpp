class Solution {
public:
    bool search(vector<int>& nums, int target) {
        function<bool(int, int)> func = [&](int left, int right) -> bool {
            if (left > right) return false;

            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;

            // Cannot determine which half is sorted due to duplicates at both ends
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                return func(left + 1, right - 1);
            }

            // Left half [left..mid] is sorted in non-decreasing order
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    return func(left, mid - 1);
                }
                return func(mid + 1, right);
            }

            // Otherwise, right half [mid..right] is sorted in non-decreasing order
            if (nums[mid] < target && target <= nums[right]) {
                return func(mid + 1, right);
            }
            return func(left, mid - 1);
        };

        return func(0, static_cast<int>(nums.size()) - 1);
    }
};