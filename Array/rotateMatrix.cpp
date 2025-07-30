class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        for(int i = 0; i < n; ++i) {
            // reverse(begin(matrix[i]), end(matrix[i]));
            int j = 0, k = n - 1;
            while(j < k) {
                swap(matrix[i][j++], matrix[i][k--]);
            }
        }
    }
};