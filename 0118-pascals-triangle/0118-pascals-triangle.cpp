class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        res.push_back({1});
        res.push_back({1,1});
        if(numRows == 1){
            return {{1}};
        }
        else if(numRows == 2){
            return {{1}, {1,1}};
        }

        for(int i = 3; i <= numRows ; i++){
            vector<int>temp(i, 1);
            for(int j = 1; j < i-1; j++){
                
                // else{
                temp[j] = res[i-2][j] + res[i-2][j-1];
                
            }
            res.push_back(temp);
        }

        return res;
    }
};