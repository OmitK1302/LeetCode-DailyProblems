class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int row = heightMap.size();
        int col = heightMap[0].size();

        vector<vector<bool>>visited(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][col - 1], {i, col - 1}});

            visited[i][0] = true;
            visited[i][col - 1] = true;
        }

        for(int i = 1; i < col - 1; i++) {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[row - 1][i], {row - 1, i}});

            visited[0][i] = true;
            visited[row - 1][i] = true;
        }


        vector<vector<int>>dir = {
            {1,0}, {0,1}, {0, -1}, {-1, 0}
        };

        int res = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int h = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for(auto& d : dir) {
                int _i = i + d[0];
                int _j = j + d[1];

                if(_i >= 0 && _i < row && _j >= 0 && _j < col && (!visited[_i][_j])) {
                    visited[_i][_j] = true;
                    int trapped = max(0, h - (heightMap[_i][_j]));
                    res += trapped;

                    int newHeight = max(h, heightMap[_i][_j]);
                    pq.push({newHeight, {_i, _j}});
                } 
            }
        }

        return res;
    }
};


