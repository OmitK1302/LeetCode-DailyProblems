class Solution {
public:
    vector<vector<int>>dist = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited) {
        if(visited[i][j]) return;
        visited[i][j] = true;
        board[i][j] = 'Y';
        int n = board.size();
        int m = board[0].size();
        for(auto& it : dist) {
            int _i = i + it[0];
            int _j = j + it[1];

            if(_i >= 0 && _i < n && _j < m && _j >= 0 && board[_i][_j] == 'O') {
                dfs(board, _i, _j, visited);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && (!visited[i][j]) && board[i][j] == 'O') {
                    dfs(board, i, j, visited);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};