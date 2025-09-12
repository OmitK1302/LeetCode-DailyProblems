class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>>live;
        vector<vector<int>>dead;

        vector<vector<int>> dir = {
            {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int nb = 0;

                for(auto& d : dir) {
                    int _i = i + d[0];
                    int _j = j + d[1];

                    if(_i >= 0 && _j >= 0 && _i < board.size() && _j < board[0].size() && board[_i][_j] == 1) {
                        nb++;
                    }
                }

                // if((i + 1 < row )&& board[i + 1][j] == 1){
                //     nb++;
                // }
                // if(i - 1 >= 0 && board[i - 1][j] == 1){
                //     nb++;
                // }
                // if(j + 1 < col && board[i][j + 1] == 1){
                //     nb++;
                // }
                // if(j - 1 >= 0 && board[i][j - 1] == 1){
                //     nb++;
                // }
                // if((i + 1 < row) && (j + 1 < col) && (board[i + 1][j + 1] == 1)){
                //     nb++;
                // }
                // if((i + 1 < row) && (j - 1 >= 0) && (board[i + 1][j - 1] == 1)){
                //     nb++;
                // }
                // if((i - 1 >= 0) && (j + 1 < col) && (board[i - 1][j + 1] == 1)){
                //     nb++;
                // }
                // if((i - 1 >= 0) && (j - 1 >= 0) && (board[i - 1][j - 1] == 1)){
                //     nb++;
                // }

                // cout<<nb<<" ";

                if(board[i][j] == 0 && nb == 3){
                    live.push_back({i, j});
                    // board[i][j] = 2; // for live
                }
                if(board[i][j] == 1){
                    if(nb < 2 || nb > 3){
                        dead.push_back({i, j});
                        // board[i][j] = 3; // for dead
                    }
                    if(nb == 2 || nb == 3){
                        live.push_back({i, j});
                        // board[i][j] = 2;
                    }
                }
            }
            // cout<<endl;
        }

        for(vector<int>& cell : live){
            board[cell[0]][cell[1]] = 1;
        }

        for(vector<int>& cell : dead){
            board[cell[0]][cell[1]] = 0;
        }

        // return board;
    }
};