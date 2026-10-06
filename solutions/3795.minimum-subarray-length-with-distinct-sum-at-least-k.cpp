class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int ans = INT_MAX, left = 0, s = 0;
        unordered_map <int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] < 2) s += nums[i];
            while (s >= k) {
                ans = min(ans, i - left + 1);
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0) s -= nums[left];  //只有哈希表中值为0时才从s中移除
                left++;
            }

        }
    return ans <= nums.size() ? ans: -1;
    }
};
