class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int res = 0;
        while(numBottles) {
            numBottles--;
            res++;
            empty++;

            if(empty == numExchange) {
                numBottles++;
                numExchange++;
                empty = 0;
            }
        }

        return res;
    }
};