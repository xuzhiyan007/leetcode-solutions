class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, s = 0, left = 0;
        unordered_map <char, int> cnt;
        for(int i = 0; i < answerKey.length(); i++) {
            cnt[answerKey[i]]++;
            s++;
            while (cnt['T'] > k && cnt['F'] >k) {
                cnt[answerKey[left]]--;
                s--;
                if (cnt[answerKey[left]] == 0) cnt.erase(answerKey[left]);
                left++;
            }
        ans = max(ans, s);
        }
    return ans;
    }
};
