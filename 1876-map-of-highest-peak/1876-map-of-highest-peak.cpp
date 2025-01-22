class Solution {
public:
    vector<vector<int>>dir = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
    vector<pair<int, int>> findSource(vector<vector<int>>& isWater) {
        vector<pair<int, int>>res;
        for(int i = 0; i < isWater.size(); i++){
            for(int j = 0; j < isWater[0].size(); j++){
                if(isWater[i][j] == 1){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>res(m, vector<int>(n, -1));
        vector<pair<int, int>> sources = findSource(isWater);
        
        queue<pair<int, int>>que;
        for(auto& i : sources){
            res[i.first][i.second] = 0;
            que.push(i);
        }
        
        while(!que.empty()){
            pair<int, int> source = que.front();
            que.pop();

            int i = source.first;
            int j = source.second;

            for(int a = 0; a < 4; a++){
                int curr_i = i + dir[a][0];
                int curr_j = j + dir[a][1];

                if(curr_i >= 0 && curr_i < m && curr_j >= 0 && curr_j < n && res[curr_i][curr_j] == -1){
                    que.push({curr_i, curr_j});
                    res[curr_i][curr_j] = res[i][j] + 1;
                }
            }
        }
        return res;
        
    }
};