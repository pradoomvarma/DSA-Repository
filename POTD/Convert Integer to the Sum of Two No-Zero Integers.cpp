class Solution {
public:

    vector<int> getNoZeroIntegers(int n) {
        auto solve = [](int num) {
            string str = to_string(num);
            for(auto ch : str) if(ch == '0') return 0;
            return 1;
        };
        for(int i = 1; i < n; ++i) {
            int j = n - i;
            if(solve(i) && solve(j)) return {i, j};
        }
        return {-1, -1};
    }
};