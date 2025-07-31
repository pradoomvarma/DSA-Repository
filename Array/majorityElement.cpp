class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = INT_MIN;
        int cnt = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(cnt == 0) {
                cnt = 1;
                cand = nums[i];
            }
            else if(cand == nums[i]) cnt++;
            else cnt--;
        }

        cnt = 0;
        for(auto el : nums) {
            if(el == cand) cnt++;
        }

        int n = nums.size();
        if(cnt > (n / 2)) return cand;
        return -1;
    }
};