class Solution {
public:
    bool isValid(vector<vector<char>>& board, int curri, int currj) {
        int cnt = 0;
        for(int i = 0; i < board.size(); i++) {
            if(board[i][currj] == board[curri][currj]) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
            }
        }
        cnt = 0;
        for(int i = 0; i < board[0].size(); i++) {
            if(board[curri][i] == board[curri][currj]) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
            }
        }

        cnt = 0;
        int tempi = (curri / 3) * 3;
        int tempj = (currj / 3) * 3;

        for(int i = tempi; i < tempi + 3; i++) {
            for(int j = tempj; j < tempj + 3; j++) {
                if(board[i][j] == board[curri][currj]) {
                    if(cnt == 1) return false;
                    cnt++;
                }
            }
        }

        return true;
    }

    bool allDone = false;
    bool solveHelper(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true; 

        if (col == 9) return solveHelper(board, row + 1, 0);

        if (board[row][col] != '.') {
            return solveHelper(board, row, col + 1);
        }

        for (char ch = '1'; ch <= '9'; ++ch) {
            board[row][col] = ch;
            if (isValid(board, row, col)) {
                if (solveHelper(board, row, col + 1)) return true;
            }
            board[row][col] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveHelper(board, 0, 0);
        
    }
};