class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = INT_MAX; //注意初始值
        int s = 0;
        int all = 0;
        int ori = k;
        k =  k == cardPoints.size() ? k : cardPoints.size() - k;  //注意k = length 的边界条件

        for (int i = 0; i < cardPoints.size(); i++){
            all += cardPoints[i];
            s += cardPoints[i];

            int left = i - k + 1;
            if (left < 0) continue;

            ans = min(ans, s);

            s -= cardPoints[left];
        }

        if ( ori == cardPoints.size())  return all; //注意k = length 的边界条件
        else return all - ans;
    }
};
