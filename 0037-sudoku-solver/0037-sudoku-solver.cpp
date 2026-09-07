#include <vector>

using namespace std;

class Solution {
    int row[9] = {0};
    int col[9] = {0};
    int box[9] = {0};
    vector<pair<int, int>> empty_cells;

    bool solve(int idx, vector<vector<char>>& board) {
        if (idx == empty_cells.size()) {
            return true;
        }

        int r = empty_cells[idx].first;
        int c = empty_cells[idx].second;
        int b = (r / 3) * 3 + (c / 3);

        for (int num = 1; num <= 9; ++num) {
            int bit = 1 << num;
            
            if (!(row[r] & bit) && !(col[c] & bit) && !(box[b] & bit)) {
                board[r][c] = num + '0';
                row[r] |= bit;
                col[c] |= bit;
                box[b] |= bit;

                if (solve(idx + 1, board)) {
                    return true;
                }

                row[r] &= ~bit;
                col[c] &= ~bit;
                box[b] &= ~bit;
                board[r][c] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int bit = 1 << num;
                    int b = (i / 3) * 3 + (j / 3);
                    
                    row[i] |= bit;
                    col[j] |= bit;
                    box[b] |= bit;
                } else {
                    empty_cells.push_back({i, j});
                }
            }
        }
        
        solve(0, board);
    }
};