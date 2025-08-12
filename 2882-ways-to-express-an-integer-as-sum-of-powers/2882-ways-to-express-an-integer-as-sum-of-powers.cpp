// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     long long helper(int n, int x, int temp, vector<int>& dp) {
//         if(n == 0) return 1;

//         if(dp[n] != -1) return dp[n];

//         // int temp =
//         long long res = 0; 
//         for(int i = temp+1; i <= n; i++) {
//             // res += helper(n- pow(i, x))
//             if((n - (int)pow(i, x)) >= 0) {
//                 res += helper(n - (int)pow(i,x), x, i, dp);
//             }
//         }

//         return dp[n] = res % MOD;
//     }

//     int numberOfWays(int n, int x) {
//         vector<int>dp(n+1, -1);
//         return helper(n, x, 0, dp) % MOD;
//     }
// };


class Solution {
public:
    int numberOfWays(int n, int x) {
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);
            if (val > n) {
                break;
            }
            for (int j = n; j >= val; j--) {
                dp[j] = (dp[j] + dp[j - val]) % mod;
            }
        }
        return dp[n];
    }
};