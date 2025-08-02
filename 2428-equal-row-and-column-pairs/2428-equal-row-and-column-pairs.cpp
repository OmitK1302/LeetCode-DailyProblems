class Solution {
public:
    int matchCol(vector<vector<int>>& grid, int curri) {
        int res = 0;
        int n = grid.size();
        for(int j = 0; j < n; j++) {
            bool match = true;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] != grid[curri][i]) {
                    match = false;
                    break;
                }
            }
            if(match) res++;
        }

        return res;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<string>row(n);
        vector<string>col(n);

        int res = 0;
        for(int i = 0; i < n; i++) {
            res += matchCol(grid, i);
        }

        return res;
    }
};