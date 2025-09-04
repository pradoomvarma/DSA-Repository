class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int st = 0, end = n * m - 1;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            int i = mid / m;
            int j = mid % m;
            if(mat[i][j] == target) return 1;
            else if(mat[i][j] > target) end = mid - 1;
            else st = mid + 1;
        }

        return 0;
    }
};