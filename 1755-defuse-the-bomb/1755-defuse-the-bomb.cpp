class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // vector<int>preSum;
        if(k == 0) {
            vector<int>res(code.size(), 0);
            return res;
        }
        // if(k )
        int n = code.size();
        vector<int>res(n, 0);
        // for(int i = 0; i < preSum.size(); i++) {
            
        // }

        // for(int i = 0; i < preSum.size(); i++) {
        //     preSum[i] += (code[(i+1)%n] + code[(i+2)%n + code[(i+3)%n]])
        // }

        // int sum = 0;
        // for(int& num : code) {
        //     sum += num;
        // }

        for(int i = 0; i < code.size(); i++) {
            int count = 0;
            for(int j =1; j <= abs(k); j++) {
                
                if(k > 0) {
                    count += code[(i+j) % n];
                }
                else{
                    count += code[(n+i-j) % n];
                }
            }
            res[i] = count;
            // if(k > 0) {
            //     int currVal = 0;
            //     for(int j = 1; j <= k; j++) {
            //         currVal += code[(i+j) % n];
            //     }

            //     code[i] = currVal;
            // }

            // else {
            //     int currVal = 0;
            //     for(int j = 1; j <= abs(k); j++) {
            //         currVal += code[(n + i - j) % k];
            //     }

            //     code[i] = currVal;
            // }
        }

        return res;

    }
};