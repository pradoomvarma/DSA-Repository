class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto cnt = [](int x) {
            string s = to_string(x);
            sort(begin(s), end(s));
            return s;
        };

        string target = cnt(n);
        for(int i = 0; i < 31; ++i) {
            if(cnt(1 << i) == target) return 1;
        }

        return 0;
    }
};