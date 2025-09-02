class Solution {
public:

    bool solve(vector<int>& weights, int days, int cap) {
        int d = 1;
        int sum = 0;

        for(auto el : weights) {
            if(el > cap) return 0;
            if(sum + el > cap) {
                d++;
                sum = el;
            }
            else sum += el;
            if(d > days) return 0;
        }

        return 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int e = accumulate(begin(weights), end(weights), 0);
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(solve(weights, days, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }

        return ans;
    }
};