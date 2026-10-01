class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool p = false;
        for (int i = 0; i < 31; i++){
            if (n == (1<<i)){
                p = true;
            }
        }
        return p;
    }
};
