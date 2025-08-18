class Solution {
public:


    bool solve(vector<double>& nums) {
        if(nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(i == j) continue;

                vector<double> next;
                for(int k = 0; k < nums.size(); ++k) {
                    if(k != i && k != j) next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];
                vector<double> arr = {a + b, a - b, b - a, a * b};
                if(fabs(a) > 1e-6) arr.push_back(a / b);
                if(fabs(b) > 1e-6) arr.push_back(b / a);

                for(auto &val : arr) {
                    next.push_back(val);
                    if(solve(next)) return 1;
                    next.pop_back();
                }
            }
        }

        return 0;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(begin(cards), end(cards));
        return solve(nums);
    }
};