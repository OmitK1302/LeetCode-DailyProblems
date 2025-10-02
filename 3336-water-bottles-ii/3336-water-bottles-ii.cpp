class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int res = 0;
        while(numBottles >= numExchange) {
            numBottles -= (numExchange - 1);
            res += numExchange;
            numExchange++;


            // numBottles--;
            // res++;
            // empty++;

            // if(empty == numExchange) {
            //     numBottles++;
            //     numExchange++;
            //     empty = 0;
            // }
        }

        return res + numBottles;
    }
};