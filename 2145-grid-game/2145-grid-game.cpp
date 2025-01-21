class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>>prefix(2, vector<long long>(n + 1, 0));

        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i][j - 1] + grid[i][j - 1];
            }
        }

        long long res = LLONG_MAX;

        for(int i = 1; i <= n; i++){
            long long currVal = max((prefix[0][n] - prefix[0][i]), prefix[1][i-1]);
            res = min(res, currVal);
        }
        return res;
    }
};