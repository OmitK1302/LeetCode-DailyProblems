class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        double val = 0;
        int res = 0;
        for(int i = 0; i < dim.size(); i++) {
            auto it = dim[i];
            double val1 = it[0] * it[0];
            double val2 = it[1] * it[1];

            double diag = sqrt(val1 + val2);

            if(diag == val) {
                if(dim[res][0] * dim[res][1] < dim[i][0] * dim[i][1]) {
                    res = i;
                }
            }

            if(diag > val) {
                val = diag;
                res = i;
            }
        }

        return dim[res][0] * dim[res][1];
    }
};