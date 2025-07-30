class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0], cnt = 1;
        int n = nums.size();

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == cand) cnt++;
            else cnt--;

            if(cnt == 0) {
                cand = nums[i];
                cnt = 1;
            }
        }

        cnt = 0;
        for(auto el : nums) {
            if(el == cand) cnt++;
        }

        return cnt > (n / 2) ? cand : -1;
    }

};