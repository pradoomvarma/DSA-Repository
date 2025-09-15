class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int mini = INT_MAX;

        for(int i = 0; i < n - k; ++i) {
            sum += cardPoints[i];
        }

        mini = min(mini, sum);

        for(int i = n - k; i < n; ++i) {
            sum += cardPoints[i];
            sum -= cardPoints[i - (n - k)];

            mini = min(mini, sum);
        }

        int total = accumulate(begin(cardPoints), end(cardPoints), 0);
        return total - mini;    // maxi
    }
};