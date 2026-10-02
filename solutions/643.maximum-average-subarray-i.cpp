class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ave = 0;
        double ans = -1e9;
        for (int i = 0; i < nums.size(); i++){
            ave += nums[i];
            
            int left = i - k + 1;
            if (left < 0){
                continue;
            }

            else{
                ans = max(ave, ans);
                ave -= nums[left];
            }
        }
        return ans/k;
    }
};
