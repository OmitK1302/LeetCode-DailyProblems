class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>res;
        for(int i = 9; i >= 0; i--) {
            int temp = pow(10, i);
            if((n / temp) > 0) {
                res.push_back((n/temp) * temp);
                n = n % temp;
            }
        }

        return res;
    }
};