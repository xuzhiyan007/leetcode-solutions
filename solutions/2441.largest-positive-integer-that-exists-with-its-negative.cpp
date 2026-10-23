class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> idx;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            auto it = idx.find(-nums[i]);
            if (it != idx.end() && abs(nums[i]) > ans) {
                ans = max(nums[i], -nums[i]);
            }
            idx[nums[i]] = i;
        }
        return ans;
    }
};
