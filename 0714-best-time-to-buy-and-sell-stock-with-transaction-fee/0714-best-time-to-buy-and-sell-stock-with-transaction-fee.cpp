class Solution {
public:
    vector<vector<int>>dp;
    int profitHelper(vector<int>& prices, int curr, int currStock, int fee) {
        if(curr == prices.size()) return 0;

        if(dp[curr][currStock] != -1) return dp[curr][currStock];

        int skip = profitHelper(prices, curr + 1, currStock, fee);
        int sell = INT_MIN;
        int buy = INT_MIN;
        if(currStock) {
            sell = profitHelper(prices, curr + 1, 0, fee) + prices[curr];
        }
        else{
            buy = profitHelper(prices, curr + 1, 1, fee) - prices[curr] - fee;
        }

        return dp[curr][currStock] = max(skip, max(buy, sell));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.resize(n+1, vector<int>(2, -1));

        return profitHelper(prices, 0, 0, fee);
    }
};