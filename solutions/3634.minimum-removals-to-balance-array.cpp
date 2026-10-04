class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int max_ = 0, left = 0;
        ranges::sort(nums);

        for (int right = 0; right < nums.size(); right++){
            while (1LL * nums[left]*k < nums[right]){
                left++;
            }

            max_ = max(max_, right - left + 1);
        }
    return nums.size() - max_;
    }
};
