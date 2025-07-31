class Solution {
public:

    // for marking rows and columns use first row and column
    // but [0][0] will be overlapping which can create confusion so 
    // consider 0th column for marking row and 0th row for marking column
    // but for 0th pos of column use variable col0 = 1
    // so now we have to mark from end and also first inside cells and
    // then first row then first column as we're using variable for column

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j == 0) col0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = n - 1; i > 0; --i) {
            for(int j = m - 1; j > 0; --j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = m - 1; j > 0; --j) {
            if(matrix[0][0] == 0) matrix[0][j] = 0;
        }

        for(int i = n - 1; i >= 0; --i) {
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};