class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];

        if(orig == color) return;

        vector<vector<int>>dir = {
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
        };

        queue<pair<int, int>>que;
        que.push({sr, sc});

        while(!que.empty()) {
            int n = que.size();
            for(int i = 0; i < n; i++) {
                pair<int, int>curr = que.front();
                que.pop();
                int curri = curr.first;
                int currj = curr.second;

                image[curri][currj] = color;

                for(int d = 0; d < 4; d++) {
                    int _i = curri + dir[d][0];
                    int _j = currj + dir[d][1];

                    if(_i >= 0 && _i < image.size() && _j >= 0 && _j < image[0].size() && image[_i][_j] == orig) {
                        que.push({_i, _j});
                        
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(image, sr, sc, color);
        return image;
    }
};