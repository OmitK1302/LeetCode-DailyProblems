class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // if(numRows == 1){
        //     return {{1}};
        // }
        // else if(numRows == 2){
        //     return {{1}, {1,1}};
        // }

        vector<vector<int>>res;
        // res.push_back({1});
        // res.push_back({1,1});

        for(int i = 0; i < numRows ; i++){
            vector<int>temp(i + 1, 1);
            for(int j = 1; j < i; j++){
                
                // else{
                temp[j] = res[i-1][j] + res[i-1][j-1];
                
            }
            res.push_back(temp);
        }

        return res;
    }
};