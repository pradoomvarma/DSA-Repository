class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int st = 0, end = n - 1;    // apply bs on col
        while(st <= end) {
            int j = st + (end - st) / 2;
            int i = -1;
            int maxi = INT_MIN;
            for(int r = 0; r < m; ++r) {    // find in col j at which row i mat[i][j] is max
                if(mat[r][j] > maxi) {
                    maxi = mat[r][j];
                    i = r;
                }
            }
            int left = j - 1 >= 0 ? mat[i][j - 1] : -1;
            int right = j + 1 < n ? mat[i][j + 1] : -1;
            if(mat[i][j] > left && mat[i][j] > right) return {i, j};
            else if(mat[i][j] < left) end = j - 1;
            else st = j + 1;
        }

        return {-1, -1};
    }
};