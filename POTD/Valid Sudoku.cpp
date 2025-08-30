class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Solution 1
        // Row check
        for (int i = 0; i < 9; ++i) {
            vector<int> cnt(10, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;  // skip empty cells
                int num = board[i][j] - '0';
                cnt[num]++;
                if (cnt[num] > 1) return false;
            }
        }

        // Column check
        for (int i = 0; i < 9; ++i) {
            vector<int> cnt(10, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;  // skip empty cells
                int num = board[j][i] - '0';
                cnt[num]++;
                if (cnt[num] > 1) return false;
            }
        }

        // 3x3 subgrid check
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                vector<int> cnt(10, 0);
                for (int i = row; i < row + 3; ++i) {
                    for (int j = col; j < col + 3; ++j) {
                        if (board[i][j] == '.') continue;  // skip empty cells
                        int num = board[i][j] - '0';
                        cnt[num]++;
                        if (cnt[num] > 1) return false;
                    }
                }
            }
        }

        return true;

        // Solution 2

        unordered_set<string> st;

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;

                string row = string(1, board[i][j]) + "_row_" + to_string(i);
                string col = string(1, board[i][j]) + "_col_" + to_string(j);
                string box = string(1, board[i][j]) + "_box_" + to_string(i / 3) + "_" + to_string(j / 3);

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end()) return 0;

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return 1;
    }
};
