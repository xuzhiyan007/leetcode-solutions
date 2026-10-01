class Solution {
public:
    bool isPowerOfThree(int n) {
        bool p = false;
        for (int i = 0; i < 26; i++){
            if (n == pow(3, i)){
                p = true;
            }
        }
        return p;
    }
};
