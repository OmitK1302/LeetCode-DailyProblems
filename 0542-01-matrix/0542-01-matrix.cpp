class Solution {
public:
    void bfs(vector<vector<int>>& mat) {
        queue<pair<int, int>>que;
        int n = mat.size();
        int m = mat[0].size();

        cout<<n<<" "<<m;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // que.push({i, j});

        vector<vector<int>>dir = {
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
        };

        int res = 0;

        while(!que.empty()) {
            int len = que.size();
            res++;
            for(int i = 0; i < len; i++) {
                pair<int, int>curr = que.front();
                que.pop();
                int curri = curr.first;
                int currj = curr.second;
                

                for(auto& d : dir) {
                    int _i = curri + d[0];
                    int _j = currj + d[1];

                    if(_i >= 0 && _i < n && _j >= 0 && _j < m) {

                        if(!visited[_i][_j]) {
                            visited[_i][_j] = true;
                            if(mat[_i][_j] == 1) {
                                mat[_i][_j] = res;
                            }

                            que.push({_i, _j});
                        }
                    }

                }
            }
        }

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        bfs(mat);
        return mat;
    }
};