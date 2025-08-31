// Solution 1

class Solution {
public:

    typedef long long ll;

    long long flowerGame(int n, int m) {
        long long ans = 0;
        
        ll odd_n = (n % 2) == 1 ? n / 2 + 1 : n / 2;
        ll even_n = n / 2;
        ll odd_m = (m % 2) == 1 ? m / 2 + 1 : m / 2;
        ll even_m = m / 2;

        ans = odd_n * even_m + even_n * odd_m;
        return ans;
    }
};

// Solution 2
class Solution {
public:

    typedef long long ll;

    long long flowerGame(int n, int m) {
        long long ans = (1ll * n * m) / 2;
        return ans;
    }
};