class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = INT_MIN, cand2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(cnt1 == 0 && nums[i] != cand2) {     // make sure if setting cand1 it should not be equal to cand2
                cnt1 = 1;
                cand1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != cand1) {    // vice versa
                cnt2 = 1;
                cand2 = nums[i];
            }
            else if(nums[i] == cand1) cnt1++;
            else if(nums[i] == cand2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0, cnt2 = 0;

        for(auto el : nums) {
            if(el == cand1) cnt1++;
            else if(el == cand2) cnt2++;
        }

        int n = nums.size();
        if(cnt1 > (n / 3)) ans.push_back(cand1);
        if(cnt2 > (n / 3)) ans.push_back(cand2);

        return ans;
    }
};