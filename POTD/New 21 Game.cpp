class Solution {
public:

    // Game will stop only when score reaches [k <= score <= n] so
    // find p(k) + p(k + 1) + ... + p(n) and return
    double new21Game(int n, int k, int maxPts) {
        vector<double> p(n + 1, 0.0);

        p[0] = 1.0;   // at starting alice already have score 0
        double probSum = k == 0 ? 0.0 : 1.0;
        for(int i = 1; i <= n; ++i) {   // calculate p[1] to p[n]
            p[i] += probSum / maxPts;
            if(i < k) probSum += p[i];
            if(i - maxPts >= 0 && i - maxPts < k) {
                probSum -= p[i - maxPts];
            }
        }

        // double res = 0.0;
        // for(int i = k; i <= n; ++i) {   // res = p[k] + ... + p[n]
        //     res += p[i];
        // }

        // return res;

        return accumulate(begin(p) + k, end(p), 0.0);
    }
};