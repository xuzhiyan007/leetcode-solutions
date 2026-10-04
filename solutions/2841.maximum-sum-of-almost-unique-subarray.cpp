class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
        long long sum = 0;
        unordered_map <int, int> cnt;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            cnt[nums[i]]++;

            int left = i - k + 1;
            if (left < 0) continue;

            if (cnt.size() >= m){
                ans = max(ans, sum);

            }

            sum -= nums[left];
            cnt[nums[left]]--;
            int out = nums[left];

            if (cnt[out] == 0){
                cnt.erase(out);
            }
        }
    return ans;
    }
};
