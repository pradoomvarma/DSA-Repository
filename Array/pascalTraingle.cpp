class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});

        if(n == 1) return ans;

        for(int i = 1; i < n; ++i) {
            vector<int> arr;
            arr.push_back(1);
            int prod = 1;

            for(int j = 1; j <= i; ++j) {
                prod *= ((i + 1) - j);          // (prod * (rowNum)) / colNum
                prod /= j;
                arr.push_back(prod);
            }

            ans.push_back(arr);
        }

        return ans;
    }
};