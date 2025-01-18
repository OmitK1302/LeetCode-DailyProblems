class Solution {
public:
    vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>>result(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});

        result[0][0] = 0;
        
        while(!pq.empty()){
            vector<int>vec = pq.top();
            pq.pop();
            int cost = vec[0];
            int i = vec[1];
            int j = vec[2];
            int gridDir = grid[i][j];

            for(int dir_i = 0; dir_i < dir.size(); dir_i++){
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n){
                    int newCost = cost + ((gridDir - 1 == dir_i) ? 0 : 1);

                    if(newCost < result[i_][j_]){
                        result[i_][j_] = newCost;
                        pq.push({newCost, i_, j_});
                    }
                }

                

            }

        }


        return result[m-1][n-1];
    }
};