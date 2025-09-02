class Solution {
public:

    bool solve(vector<int>& bloomDay, int m, int k, int days) {
        int cnt = 0, bq = 0;
        for(auto el : bloomDay) {
            if(el > days) {
                cnt = 0;
                continue;
            }
            cnt++;
            if(cnt == k) {
                bq++;
                cnt = 0;
            }

            if(bq >= m) return 1;
        }

        if(bq >= m) return 1;
        return 0;
    }    

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1ll * m * k > n) return -1;

        int ans = -1;
        int low = 0;
        int high = *max_element(begin(bloomDay), end(bloomDay));

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(solve(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};