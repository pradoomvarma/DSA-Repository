class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char &ch) {
        for(int i = 0; i < 9; ++i) {
            // row check
            if(board[row][i] != '.' && board[row][i] == ch) return 0;

            // col check
            if(board[i][col] != '.' && board[i][col] == ch) return 0;

            // box check
            int r = (row / 3) * 3 + (i / 3);
            int c = ((col / 3) * 3) + (i % 3);
            if(board[r][c] != '.' && board[r][c] == ch) return 0;
        }

        return 1;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isSafe(board, i, j, ch)) {
                            board[i][j] = ch;
                            if(solve(board)) return 1;
                            board[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }
        }

        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};