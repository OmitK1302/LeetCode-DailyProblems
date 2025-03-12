class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        unordered_map<int, int>aliceMap;
        int aliceSum = 0;
        int bobSum = 0;
        for(int& num : aliceSizes){
            aliceSum += num;
            aliceMap[num] = 1;
        }

        for(int& num : bobSizes){
            bobSum += num;
        }

        int diff = max(aliceSum, bobSum) - ((aliceSum + bobSum) / 2);

        for(int& num : bobSizes){
            if(aliceMap[(aliceSum > bobSum) ? num + diff : num - diff] == 1){
                // vector<int>res;
                if(aliceSum > bobSum){
                    return {num + diff, num};
                }
                else{
                    return {num - diff, num};
                }
                break;
            }
        }

        return {-1, -1};
    }
};