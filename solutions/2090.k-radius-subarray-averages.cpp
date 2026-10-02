class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0; //注意和的类型
        std::vector<int> avgs(n, -1);

        for (int i = 0 ; i < n ; i++){
            sum += nums[i];

            int left = i - 2*k ;

            if (left < 0){
                continue;
            }

            avgs[i - k] = sum /(2 * k + 1);
            sum -= nums[left];


        }
        return avgs;
    }
};
