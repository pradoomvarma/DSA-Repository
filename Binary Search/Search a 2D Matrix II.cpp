class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0, c = m - 1;   // bcoz then row is decreasing and col is increasing so we can eliminate
                                // row or col everytime. r = n - 1, c = 0 can also be starting point for
                                // same reason  // TC = O(n + m)
        while(r < n && c >= 0) {
            if(matrix[r][c] == target) return 1;
            else if(matrix[r][c] < target) r++;
            else c--;
        }

        return 0;
    }
};