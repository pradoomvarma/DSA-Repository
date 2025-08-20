class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> arr(n, vector<int>(m, 0));

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 || j == 0) arr[i][j] = matrix[i][j];
                else if(matrix[i][j] != 0) arr[i][j] = min({arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1]}) + 1;
                sum += arr[i][j];
            }
        }

        return sum;
    }
};