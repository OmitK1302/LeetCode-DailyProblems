class Solution {
public:
    int setBitCloseFour(int value) {
        // int res = 0;
        for (int i = 31; i >= 0; i--) {
            if (value & (1 << i)) {
                return i % 2 == 0 ? i / 2 : (i - 1) / 2;
            }
        }

        return 0;
    }

    long long minOperations(vector<vector<int>>& queries) {
        // return 0;
        // cout<<setBitCloseFour(255); // 3
        
        long long res = 0;
        for (auto& it : queries) {
            long long tempBit = setBitCloseFour(it[0]);

            long long currRes = 0;
            long long templ = 1 << (2 * tempBit);


            // cout<<endl<<tempBit<<" "<<templ<<endl;

            long long curr = it[0];
            while (!(templ > it[1])) {
                long long tempr = (4 * templ) - 1;
                // cout<<tempr<<endl;

                if (tempr <= it[1]) {
                    currRes += (tempr - curr + 1) * (tempBit + 1);
                } else {
                    currRes += (it[1] - curr + 1) * (tempBit + 1);
                }

                tempBit++;
                curr = tempr + 1;
                templ = 1 << (2 * tempBit);
            }

            res += ((currRes / 2) + (currRes % 2));
            // cout<<res<<endl;
        }

        return res;
    }
};