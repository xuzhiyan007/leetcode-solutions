class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int bestRight = INT_MAX, n = 0, left = 0;
        int bestLeft = 0, len = INT_MAX, sum = 0;
        for (int i = 0; i < s.length(); i++) {
            n += s[i] - '0';
            while (n >= k) {
                if (n == k && 
                    (i - left + 1 < len || 
                     (i - left + 1 == len && s.compare(left, i - left + 1, s, bestLeft, len) < 0))) {
                    bestRight = i;
                    bestLeft = left;
                    len = bestRight - bestLeft + 1;
                    sum = n;
                }
                n -= s[left] - '0';
                left++;
            }
        }
    return sum == k ? s.substr(bestLeft, len): "";
    }
};
