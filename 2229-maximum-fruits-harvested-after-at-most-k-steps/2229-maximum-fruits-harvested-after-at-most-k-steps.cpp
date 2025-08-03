class Solution {
public:

    int lowerBnd(vector<vector<int>>& fruitsSm, int val) {
        int l = 0;
        int r = fruitsSm.size() - 1;

        int res = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(fruitsSm[mid][0] > val) {
                r = mid - 1;
            }
            else{
                res = mid;
                l = mid + 1;
            }
        }

        return res == -1 ? 0 : fruitsSm[res][1];
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        vector<vector<int>>fruitsSm;
        int preVal = 0;
        for(int i = 0; i < fruits.size(); i++) {
            preVal += fruits[i][1];
            fruitsSm.push_back({fruits[i][0], preVal});
        }

        for(auto& it : fruitsSm) {
            cout<<it[0]<<" "<<it[1]<<endl;;
        }

        int res = 0;

        // int l = startPos, r = startPos + k;
        // while(startPos - l < k/2) {

        //     int val1 = lowerBnd(fruitsSm, l - 1);
        //     int val2 = lowerBnd(fruitsSm, r);
        //     res = max(res, val2 - val1);
        //     l--;
        //     r-=2;
        // }
        
        // l = startPos - k, r = startPos;
        // while(r - startPos < k/2) {
        //     int val1 = lowerBnd(fruitsSm, l - 1);
        //     int val2 = lowerBnd(fruitsSm, r);
        //     res = max(res, val2 - val1);
        //     r++;
        //     l+=2;
        // }

        // Left first, then right
        for (int leftSteps = 0; leftSteps <= k; ++leftSteps) {
            int left = startPos - leftSteps;
            int right = startPos + max(0, k - 2 * leftSteps);

            int val1 = lowerBnd(fruitsSm, left - 1);
            int val2 = lowerBnd(fruitsSm, right);

            res = max(res, val2 - val1);
        }

        // Right first, then left
        for (int rightSteps = 0; rightSteps <= k; ++rightSteps) {
            int right = startPos + rightSteps;
            int left = startPos - max(0, k - 2 * rightSteps);

            int val1 = lowerBnd(fruitsSm, left - 1);
            int val2 = lowerBnd(fruitsSm, right);

            res = max(res, val2 - val1);
        }



        return res;

    }
};

