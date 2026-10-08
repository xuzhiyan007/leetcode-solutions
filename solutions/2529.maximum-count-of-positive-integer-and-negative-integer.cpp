class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums, 0);
        int pos = nums.size() - lower_bound(nums, 1);
        return max(neg, pos);
    }
};
