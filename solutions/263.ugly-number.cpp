class Solution {
public:
    bool isUgly(int n) {
        while (n){
            if (n % 2 == 0){
                n /= 2;
            }

            else if (n % 3 == 0){
                n /= 3;
            }

            else if (n % 5 == 0){
                n /= 5;
            }

            else break; //加退出循环的逻辑，不然会导致死循环
        }

        return n == 1;
    }
};
