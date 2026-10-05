class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, left = 0, len = 0;
        unordered_map <int, int> cnt;

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            while (cnt[nums[i]] > k) {
                cnt[nums[left]]--;
                left++;
                if (cnt[nums[left]] == 0) cnt.erase(nums[left]);
            }
            len = i - left + 1;
            ans = max(ans, len);
        } 
        return ans;
    }
};
