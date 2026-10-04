class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, left = 0;
        unordered_map <int, int> cnt;

        for (int right = 0; right < nums.size(); right++){
            cnt[nums[right]]++;

            while (cnt[0] > 1){
                cnt[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left);

        }
    return ans;    
    }
};
