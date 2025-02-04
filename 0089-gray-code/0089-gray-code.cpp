class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>res;
        int b = pow(2, n);
        // Method 2: using Bit manipulation
        for(int i = 0; i < (1<<n); i++){
            res.push_back((i^(i>>1)));
        }

        return res;
        
        // Method 1: Using math
        // res.push_back(0);

        // for(int i = 0; i < n; i++){
        //     int temp = pow(2, i);
        //     int currSize = res.size();

        //     for(int j = currSize - 1; j >= 0; j--){
        //         res.push_back(temp + res[j]);
        //     }
        // }

        // return res;
    }
};