class Solution {
public:

    int minStep(int stPos, int left, int right) {
        return min(abs(stPos - left) + (right - left), abs(right - stPos) + (right - left));
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxi = 0, sum = 0, i = 0;

        for(int j = 0; j < n; ++j) {
            sum += fruits[j][1];

            while(i <= j && minStep(startPos, fruits[i][0], fruits[j][0]) > k) {
                sum -= fruits[i][1];
                ++i;
            }

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};