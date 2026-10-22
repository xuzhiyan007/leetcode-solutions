class Solution {
public:
    // long long lower_bound(vector<int>& nums, int target) {
    //     long long left = 0, right = nums.size() - 1;
    //     while (left <= right) {
    //         long long mid = left + (right - left)/2;
    //         if (nums[mid] >= target) {
    //             right = mid - 1;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
    //     return left;
    // }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int k = nums[i];
            auto left = lower_bound(nums.begin(), nums.begin() + i, lower - k);
            auto right = lower_bound(nums.begin(), nums.begin() + i, upper - k + 1) - 1;
            ans += right - left + 1;
        }
        return ans;
    }
};
