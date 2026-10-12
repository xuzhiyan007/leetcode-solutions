class Solution {
public:
    int lower_bound(vector<int>& nums, long long target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ranges::sort(potions);
        for (int i = 0; i < spells.size(); i++) {
            int spell = spells[i];

            long long minPotion = (success + spell - 1)/spell;  //浮点数的向上取整 
            spells[i] = potions.size() - lower_bound(potions, minPotion);
        }
        return spells;
    }
};
