class Solution {
public:
    vector<vector<vector<int>>>dp;
    int profitHelper(vector<int>& prices, int curr, int currStock, int transac, int k) {
        if(curr == prices.size()) return 0;
        if(transac > k) {
            return INT_MIN + 1e5;
        }

        if(dp[curr][currStock][transac] != -1) return dp[curr][currStock][transac];

        int skip = profitHelper(prices, curr + 1, currStock, transac, k);
        int sell = INT_MIN;
        int buy = INT_MIN;
        if(currStock) {
            sell = profitHelper(prices, curr + 1, 0, transac, k) + prices[curr];
        }
        else{
            buy = profitHelper(prices, curr + 1, 1, transac + 1, k) - prices[curr];
        }

        return dp[curr][currStock][transac] = max(skip, max(buy, sell));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return profitHelper(prices, 0, 0, 0, k);
    }
};
