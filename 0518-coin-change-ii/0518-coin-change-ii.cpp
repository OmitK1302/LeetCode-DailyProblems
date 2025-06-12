class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long>dp(amount+1, 0);
        dp[0] = 1;

        for(int& coin : coins) {
            for(int i = 0; i <= amount; i++) {
                // if(i + coin <= amount) {
                    if(i - coin >= 0) {
                        dp[i] += dp[i - coin];

                    } 
                    // dp[i + coin] += 1;
                // }
            }
        }

        return dp[amount];
    }
};