class Solution {
public:
    int helperArea(vector<vector<int>>& grid, int starti, int startj, int endi, int endj) {
        int mxCol = 0, mxRow = 0;
        int strtCol = endj + 1;
        int strtRow = endi + 1;
        bool hasOne = false;
        for(int i = starti; i <= endi; i++) {
            for(int j = startj; j <= endj; j++) {
                if(grid[i][j] == 1) {
                    hasOne = true;
                    strtCol = min(strtCol, j);
                    strtRow = min(strtRow, i);
                    mxCol = max(mxCol, j+1);
                    mxRow = max(mxRow, i+1);
                }
            }
        }

        int height = mxRow - strtRow;
        int width = mxCol - strtCol;
        return hasOne ? height * width : 0;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();


        for(int i = 1; i < grid.size(); i++) {
            int minVal = INT_MAX;
            for(int j = 1; j < grid[0].size(); j++) {
                int topLeft = helperArea(grid, 0, 0, i-1, j-1);
                int topRight = helperArea(grid, 0, j, i-1, n-1);

                // cout<<topLeft<<" "<<topRight<<endl;

                minVal = min(minVal, topLeft + topRight);
            }

            int firstSplit = helperArea(grid, i, 0, m-1, n-1);
            res = min(res, minVal + firstSplit);

           
            // cout<<res;
            // cout<<endl;
            // cout<<endl;
            minVal = INT_MAX;

            firstSplit = helperArea(grid, 0, 0, i-1, n-1);
            for(int j = 1; j < grid[0].size(); j++) {
                int btmLeft = helperArea(grid, i, 0, m-1, j-1);
                int btmRight = helperArea(grid, i, j, m-1, n-1);

                // cout<<btmLeft<<" "<<btmRight<<endl;
                minVal = min(minVal, btmLeft + btmRight);
            }

             for(int k = i + 1; k < grid.size(); k++) {
                int secSplit = helperArea(grid, i, 0, k-1, n-1);
                int thrdSplit = helperArea(grid, k, 0, m-1, n-1);

                cout<<secSplit<<" "<<thrdSplit<<endl;

                minVal = min((secSplit + thrdSplit), minVal);
            }
            cout<<firstSplit<<endl;
            res = min(res, minVal + firstSplit);
            cout<<res;
            cout<<endl;
            cout<<endl;
        }

        for(int j = 1; j < grid[0].size(); j++) {
            int minVal = INT_MAX;
            for(int i = 1; i < grid.size(); i++) {
                int leftUp = helperArea(grid, 0, 0, i-1, j-1);
                int leftDown = helperArea(grid, i, 0, m-1, j-1);

                // cout<<topLeft<<" "<<topRight<<endl;

                minVal = min(minVal, leftUp + leftDown);
            }
            
            
            res = min(res, minVal + helperArea(grid, 0, j, m-1, n-1));
            // cout<<res;
            // cout<<endl;
            // cout<<endl;
            minVal = INT_MAX;

            int firstSplit = helperArea(grid, 0, 0, m-1, j-1);
            for(int i = 1; i < grid.size(); i++) {
                int rightUp = helperArea(grid, 0, j, i-1, n-1);
                int rightDown = helperArea(grid, i, j, m-1, n-1);

                // cout<<btmLeft<<" "<<btmRight<<endl;
                minVal = min(minVal, rightUp + rightDown);
            }
            for(int k = j + 1; k < grid[0].size(); k++) {
                int secSplit = helperArea(grid, 0, j, m-1, k-1);
                int thrdSplit = helperArea(grid, 0, k, m-1, n-1);

                // cout<<secSplit<<" "<<thrdSplit<<endl;
                minVal = min((secSplit + thrdSplit), minVal);
            }
            res = min(res, minVal + firstSplit);
            // cout<<res;
            // cout<<endl;
            // cout<<endl;
        }


        return res;
    }
};