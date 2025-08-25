class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 0, j = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int>res;

        int val = m + n - 1;
        bool prim = true;
        for(int k = 0; k < val; k++) {
            if(prim) {
                while(i >= 0 && j < n) {
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if((i < 0 && j >= n) || j >= n) {
                    i += 2;
                    j--;
                }
                else if(i < 0) {
                    i = 0;
                }
            }

            else if(!prim) {
                while(i < m && j >= 0) {
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }

                if(i >= m) {
                    j += 2;
                    i--;
                }
                else if(j < 0) {
                    j = 0;
                }

                // j = 0;
            }

            prim = !prim;
        }


        // if(val % 2 != 0) {
        //     i = min(m, (val / 2));
        //     j = min(n, (val / 2));

        //     for(int k = 0; k < n; k++) {
        //         res.push_back(mat[maini][mainj]);
        //         i--;
        //         j++;
        //     }

        //     prim = false;
        // }

        // for(int k = 0; k < val/2; k++) {
        //     if(prim) {
        //         while(i >= 0 && j < n) {
        //             res.push_back(mat[i][j]);
        //             i--;
        //             j++;
        //         }

        //         i += 2;
        //         j--;
        //     }

        //     else if(!prim) {
        //         while(i < m && j >= 0) {
        //             res.push_back(mat[i][j]);
        //             i++;
        //             j--;
        //         }

        //         j += 2;
        //         i--;
        //     }

        //     prim = !prim;
        // }

        return res;
    }
};