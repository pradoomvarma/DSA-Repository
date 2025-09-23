class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(auto el : nums) {
            if(el % 2 == 0) ans = ans | el;
        }

        return ans;
    }
};