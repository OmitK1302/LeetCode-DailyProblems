class Solution {
public:
    vector<vector<int>>dp;
    int profitHelper(vector<int>& prices, int curr, int currStock) {
        if(curr >= prices.size()) return 0;

        if(dp[curr][currStock] != -1) return dp[curr][currStock];

        int skip = profitHelper(prices, curr + 1, currStock);
        int sell = INT_MIN;
        int buy = INT_MIN;
        if(currStock) {
            sell = profitHelper(prices, curr + 2, 0) + prices[curr];
        }
        else{
            buy = profitHelper(prices, curr + 1, 1) - prices[curr];
        }

        return dp[curr][currStock] = max(skip, max(buy, sell));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<int>(2, -1));

        return profitHelper(prices, 0, 0);
    }
};