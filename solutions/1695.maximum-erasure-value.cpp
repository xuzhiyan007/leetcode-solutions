class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, left = 0, s = 0;
        unordered_map <int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            cnt[nums[i]]++;

            while (cnt[nums[i]] > 1) {
            cnt[nums[left]]--;
            s -= nums[left];
            left++;
            if (cnt[nums[left]] == 0) cnt.erase(nums[left]);
            }
        ans = max(ans, s);
        }
    return ans;
    }
};
