class Solution {
public:
    int subtractProductAndSum(int n) {
        int add = n;
        
        int sum = 0;
        while(add > 0){
                sum += add % 10;
                add /= 10;
            }
            add = sum;
        
        //cout << add << endl;

        int mul = n;
      
        int ans = 1;
            while(mul > 0){
                ans *= mul % 10;
                mul /= 10;
            }
            mul = ans;    

    return mul - add;
    }
};
