// User function Template for C++

class Solution {
  public:
    
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
  
    void dfs(int x, int y, int i, int j, set<pair<int, int>> &temp, vector<vector<int>>& grid) {
        grid[x][y] = 0;
        temp.insert({x - i, y - j});
        
        for(int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                dfs(nx, ny, i, j, temp, grid);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n = grid.size();
        m = grid[0].size();
        set<set<pair<int, int>>> st;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    set<pair<int, int>> temp;
                    dfs(i, j, i, j, temp, grid);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
    }
};
