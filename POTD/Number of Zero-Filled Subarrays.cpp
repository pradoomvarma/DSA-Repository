class Solution {
public:

    typedef long long ll;

    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0;
        ll cnt = 0;

        for(int j = 0; j < nums.size(); ++j) {
            if(nums[j] != 0) {
                i = j + 1;
                continue;
            }

            cnt += (j - i + 1);
        }

        return cnt;
    }
};