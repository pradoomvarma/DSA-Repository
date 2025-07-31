class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int stRow = 0, endRow = n - 1;
        int stCol = 0, endCol = m - 1;
        int total = n * m;
        int cnt = 0;

        vector<int> ans;

        while(cnt < total) {
            // first row
            for(int i = stRow; i <= endCol && cnt < total; ++i) {
                ans.push_back(mat[stRow][i]);
                cnt++;
            }
            stRow++;

            // last col
            for(int i = stRow; i <= endRow && cnt < total; ++i) {
                ans.push_back(mat[i][endCol]);
                cnt++;
            }
            endCol--;

            // last row
            for(int i = endCol; i >= stCol && cnt < total; --i) {
                ans.push_back(mat[endRow][i]);
                cnt++;
            }
            endRow--;

            // first col
            for(int i = endRow; i >= stRow && cnt < total; --i) {
                ans.push_back(mat[i][stCol]);
                cnt++;
            }
            stCol++;
        }

        return ans;
    }
};