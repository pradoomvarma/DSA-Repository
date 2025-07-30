class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();
        vector<int> ans(n, 0);

        for(auto el : nums) {
            if(el >= 0) {
                ans[i] = el;
                i += 2;
            }
            else {
                ans[j] = el;
                j += 2;
            }
        }

        return ans;
    }
};