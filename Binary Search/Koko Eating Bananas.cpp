class Solution {
public:

    bool solve(vector<int>& piles, int h, int k) {
        for(auto el : piles) {
            h -= el % k == 0 ? el / k : (el / k) + 1;
            if(h < 0) return 0;
        }

        return 1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = -1;
        int st = 1;
        int e = *max_element(begin(piles), end(piles));

        while(st <= e) {
            int mid = st + (e - st) / 2;
            if(solve(piles, h, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else st = mid + 1;
        }

        return ans;
    }
};