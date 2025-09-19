class Solution {
public:

    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>>& board) {
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 'X' || vis[x][y]) return;

        vis[x][y] = 1;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            dfs(nx, ny, vis, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i = 0; i < n; ++i) {
            if(board[0][i] == 'O') dfs(0, i, vis, board);
            if(board[m - 1][i] == 'O') dfs(m - 1, i, vis, board);
        }

        for(int i = 0; i < m; ++i) {
            if(board[i][0] == 'O') dfs(i, 0, vis, board);
            if(board[i][n - 1] == 'O') dfs(i, n - 1, vis, board);
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};