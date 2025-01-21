class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>>indexMap;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                indexMap[mat[i][j]] = {i, j};
            }
        }

        unordered_map<int, int>rowMap;
        unordered_map<int, int>colMap;
        for(int i = 0; i < arr.size(); i++){
            int a = indexMap[arr[i]].first;
            int b = indexMap[arr[i]].second;

            rowMap[a]++;
            colMap[b]++;
            if(rowMap[a] == n || colMap[b] == m) return i;
        }

        return -1;
    }
};