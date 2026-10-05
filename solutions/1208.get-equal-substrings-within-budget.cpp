class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, cost = 0, left = 0;
        for (int i = 0; i < s.length(); i++){
            cost += abs(s[i] - t[i]);
            while (cost > maxCost){
                cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, i - left + 1);
            
        }

    return ans;
    }
};
