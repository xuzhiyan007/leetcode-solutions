class Solution {
public:
    int addDigits(int num) {
        //int sum = 0;
        while (num >= 10){
            int sum = 0;  //计数器每轮清零
            while (num > 0){
                sum += num % 10;
                num /= 10;
            }
            num = sum;  //当>=10的时候继续拆解
        }
        return num;
    }
};
