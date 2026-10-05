class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, s = 0, left = 0, cnt[2]{};
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            s++;

            while (cnt[0] > k) {
                cnt[nums[left]]--;
                left++;
                s--;
            }
        ans = max(s, ans);
        }
    return ans;
    }
};
