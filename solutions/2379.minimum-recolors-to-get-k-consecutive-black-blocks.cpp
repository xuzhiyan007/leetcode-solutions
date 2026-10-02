class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 1e9;
        int n = blocks.size();
        int num = 0;
        for (int i = 0; i < n; i++){
     
            if (blocks[i] == 'W'){
                num ++;
            }

            int left = i - k + 1;

            if (left < 0) continue;

            ans = min(num, ans);

            if (blocks[left] == 'W'){
                num--;
            }
        }
    return ans;
    }
};
