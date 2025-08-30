class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int total = n * m;
        int cnt = 0;
        int i = 0, j = 0;
        vector<int> ans;
        int dir = 1;    // 1 -> UP & 0 -> DOWN
        while(cnt < total) {
            if(dir) {
                while(i >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                    i--, j++;
                    cnt++;
                }
                ++i;
                if(j >= m) i++, j--;
            }
            else {
                while(j >= 0 && i < n) {
                    ans.push_back(mat[i][j]);
                    i++, j--;
                    cnt++;
                }
                ++j;
                if(i >= n) i--, j++;
            }
            dir = 1 - dir;
        }

        return ans;
    }
};