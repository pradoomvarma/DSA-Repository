class Solution {
public:
    const long long mod = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> arr;
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 1) arr.push_back((1LL << i) % mod);
        }

        vector<int> ans;
        for (auto &q : queries) {
            int i = q[0];
            int j = q[1];
            long long prod = 1;
            
            for(int k = i; k <= j; ++k) {
                prod = (prod * arr[k]) % mod;
            }

            ans.push_back(prod);
        }
        return ans;
    }
};
