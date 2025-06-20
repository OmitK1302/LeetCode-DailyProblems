class Solution {
public:
    vector<vector<int>>dp;
    int profitHelper(vector<int>& prices, int curr, int currStock) {
        if(curr == prices.size()) return 0;

        if(dp[curr][currStock] != -1) return dp[curr][currStock];

        int skip = profitHelper(prices, curr + 1, currStock);
        int sell = INT_MIN;
        int buy = INT_MIN;
        if(currStock) {
            sell = profitHelper(prices, curr + 1, 0) + prices[curr];
        }
        else{
            buy = profitHelper(prices, curr + 1, 1) - prices[curr];
        }

        return dp[curr][currStock] = max(skip, max(buy, sell));
    }





    // int profitHelper(vector<int>& prices, int currStock, int currInd) {

    //     if(currInd == prices.size()) return 0;

    //     if(dp[currInd][currStock] != -1) {
    //         return dp[currInd][currStock];
    //     } 

    //     int skipPurch = profitHelper(prices, currStock, currInd + 1);

    //     if(currStock == 1) {
    //         int sellStock = profitHelper(prices, currStock - 1, currInd + 1) + prices[currInd];
    //         dp[currInd][currStock] = max(skipPurch, sellStock); 
    //     }

    //     else{
    //         int purchStock = profitHelper(prices, currStock + 1, currInd + 1) - prices[currInd];
    //         dp[currInd][currStock] = max(skipPurch, purchStock); 
    //     }

    //     return dp[currInd][currStock];
    // }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return profitHelper(prices, 0, 0);
    }
};