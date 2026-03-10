class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row_mask(9, 0);
        vector<int> col_mask(9, 0);
        vector<int> box_mask(9, 0);
        bool solved = false;

        // initialize masks from given board
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] != '.') {
                    int val = board[row][col] - '0';
                    int box = (row / 3) * 3 + (col / 3);
                    row_mask[row] |= (1 << val);
                    col_mask[col] |= (1 << val);
                    box_mask[box] |= (1 << val);
                }
            }
        }

        auto dfs = [&](int col, int row, vector<vector<char>> &cur_board,
                       vector<int> &row_mask, vector<int> &col_mask, vector<int> &box_mask, auto &&self) -> void {
            if (solved) return;

            if (row == 9) {
                board = cur_board;
                solved = true;
                return;
            }

            auto check = [&](int val) -> bool {
                int box = (row / 3) * 3 + (col / 3);
                return !(row_mask[row] & (1 << val)) &&
                       !(col_mask[col] & (1 << val)) &&
                       !(box_mask[box] & (1 << val));
            };

            if (cur_board[row][col] == '.') {
                for (int i = 1; i <= 9; ++i) {
                    if (check(i)) {
                        int box = (row / 3) * 3 + (col / 3);
                        cur_board[row][col] = i + '0';
                        row_mask[row] |= (1 << i);
                        col_mask[col] |= (1 << i);
                        box_mask[box] |= (1 << i);

                        if (col < 8) {
                            self(col + 1, row, cur_board, row_mask, col_mask, box_mask, self);
                        } else {
                            self(0, row + 1, cur_board, row_mask, col_mask, box_mask, self);
                        }

                        if (solved) return;

                        cur_board[row][col] = '.';
                        row_mask[row] &= ~(1 << i);
                        col_mask[col] &= ~(1 << i);
                        box_mask[box] &= ~(1 << i);
                    }
                }
            } else {
                if (col < 8) {
                    self(col + 1, row, cur_board, row_mask, col_mask, box_mask, self);
                } else {
                    self(0, row + 1, cur_board, row_mask, col_mask, box_mask, self);
                }
            }
        };

        vector<vector<char>> temp = board;
        dfs(0, 0, temp, row_mask, col_mask, box_mask, dfs);
    }
};