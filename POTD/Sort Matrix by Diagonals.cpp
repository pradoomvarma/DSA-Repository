// Solution 1
class Solution {
public:

    void solve(vector<vector<int>>& grid, int row, int col, bool asc) {
        int n = grid.size();

        vector<int> temp;
        int i = row, j = col;
        while(i < n && j < n) {
            temp.push_back(grid[i][j]);
            ++i, ++j;
        }

        if(asc) sort(begin(temp), end(temp));
        else sort(rbegin(temp), rend(temp));
        i = row, j = col;
        for(auto it : temp) {
            grid[i][j] = it;
            ++i, ++j;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // decreasing part
        for(int i = 0; i < n; ++i) {
            solve(grid, i, 0, 0);
        }

        // increasing part
        for(int i = 1; i < n; ++i) {
            solve(grid, 0, i, 1);
        }

        return grid;
    }
};