class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, int>row_map;
        unordered_map<int, int>col_map;
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    row_map[i]++;
                    col_map[j]++;
                }
            }
        }


        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && (row_map[i] > 1 || col_map[j] > 1)){
                    res++;
                }
            }
        }

        return res;
    }
};