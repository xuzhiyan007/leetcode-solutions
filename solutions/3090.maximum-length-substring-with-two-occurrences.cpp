class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0, left = 0, n = s.length();
        unordered_map <char, int> cnt;

        for (int right = 0; right < n; right++){
            cnt[s[right]]++;

            while (cnt[s[right]] > 2){
                cnt[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);

        }

    return ans;
    }
};
