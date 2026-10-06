class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, s = 0, left = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            sum += nums[i];
            while (s >= target) {
                ans = min(i - left + 1, ans);
                s -= nums[left];
                left++;
            }
        }
        if (sum < target) ans = 0;
    return ans;
    }
};
