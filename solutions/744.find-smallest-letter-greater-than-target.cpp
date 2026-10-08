class Solution {
public:
    int lower_bound(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (letters[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = lower_bound(letters, char (int(target)+1));
        int ans = letters[idx];
        if (idx == letters.size()) ans = letters[0];
        return ans;
    }
};
