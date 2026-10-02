class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int vow = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vow++;
            }

            int left = i - k + 1;

            if (left < 0){
                continue;
            }

            ans = max(ans, vow);

            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u'){
                vow--;
            }
        }

        return ans;
    }
};
