class Solution {
public:
    vector<vector<vector<int>>>dp;
    int profitHelper(vector<int>& prices, int curr, int currStock, int transac) {
        if(curr == prices.size()) return 0;
        if(transac > 2) {
            return INT_MIN + 1e5;
        }

        if(dp[curr][currStock][transac] != -1) return dp[curr][currStock][transac];

        int skip = profitHelper(prices, curr + 1, currStock, transac);
        int sell = INT_MIN;
        int buy = INT_MIN;
        if(currStock) {
            sell = profitHelper(prices, curr + 1, 0, transac) + prices[curr];
        }
        else{
            buy = profitHelper(prices, curr + 1, 1, transac + 1) - prices[curr];
        }

        return dp[curr][currStock][transac] = max(skip, max(buy, sell));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        return profitHelper(prices, 0, 0, 0);
    }
};