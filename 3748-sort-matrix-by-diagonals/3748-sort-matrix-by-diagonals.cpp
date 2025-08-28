class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int numOfDiag = (2*n) - 1;

        // for(int k = 0; k < numOfDiag; i++) {
        for(int i = 0; i < n; i++) {
            int tempi = i;
            int tempj = 0;

            vector<int>temp;
            while(tempi < n) {
                temp.push_back(grid[tempi][tempj]);
                tempi++;
                tempj++;
            }

            sort(temp.rbegin(), temp.rend());

            tempi = i;
            tempj = 0;
            while(tempi < n) {
                grid[tempi][tempj] = temp[tempj];
                tempi++;
                tempj++;
            }
        }

        for(int j = 1; j < n; j++) {
            int tempi = 0;
            int tempj = j;

            vector<int>temp;
            while(tempj < n) {
                temp.push_back(grid[tempi][tempj]);
                tempi++;
                tempj++;
            }

            sort(temp.begin(), temp.end());

            tempi = 0;
            tempj = j;
            while(tempj < n) {
                grid[tempi][tempj] = temp[tempi];
                tempi++;
                tempj++;
            }
        }

        return grid;
        // }
    }
};