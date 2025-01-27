class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>res;
        res.push_back(0);

        for(int i = 0; i < n; i++){
            int temp = pow(2, i);
            int currSize = res.size();

            for(int j = currSize - 1; j >= 0; j--){
                res.push_back(temp + res[j]);
            }
        }

        return res;
    }
};