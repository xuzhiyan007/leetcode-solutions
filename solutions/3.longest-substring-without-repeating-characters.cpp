class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = 0;
        int left = 0;
        unordered_map <int, int> cnt;
        for (int i = 0; i < s.length(); i++){
            cnt[s[i]]++;
            
            while(cnt[s[i]] > 1){
                cnt[s[left]]--;
                left++;
            }

            ans = max(ans, i - left + 1);

        }
    
    return ans;
    }
};
