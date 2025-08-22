class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mxCol = 0, mxRow = 0;
        int strtCol = grid[0].size();
        int strtRow = grid.size();
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    strtCol = min(strtCol, j);
                    strtRow = min(strtRow, i);
                    mxCol = max(mxCol, j+1);
                    mxRow = max(mxRow, i+1);
                }
            }
        }

        int height = mxRow - strtRow;
        int width = mxCol - strtCol;

        return height * width;
    }
};