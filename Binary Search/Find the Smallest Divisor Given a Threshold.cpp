class Solution {
public:

    bool solve(vector<int>& nums, int thres, int div) {
        int sum = 0;
        for(auto el : nums) {
            sum += ceil(1.0 * el / div);
            if(sum > thres) return 0;
        }

        if(sum > thres) return 0;
        return 1;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1;
        int e = *max_element(begin(nums), end(nums));
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(solve(nums, threshold, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }

        return ans;
    }
};