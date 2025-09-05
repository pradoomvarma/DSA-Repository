class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int t = 1; t <= 60; ++t) {
            long long val = 1ll * num1 - (1ll * t * num2);
            if(val < 0) return -1;
            int minBits = __builtin_popcountll(val);
            if(minBits <= t && t <= val) return t;
        }

        return -1;
    }
};