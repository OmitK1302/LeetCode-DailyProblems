class Solution {
public:
// MEMOISATION but it causes MLE ------------------------------------------------------------------------------------------------------------------------
    double helper(int A, int B, vector<vector<double>>& dp) {
        if(A <= 0 && B <= 0) return 0.5;
        if(A <= 0 && B > 0) return 1;
        if(A > 0 && B <= 0) return 0;

        if(dp[A][B] != -1) return dp[A][B]; 

        double val1 = helper(A - 4, B, dp);
        double val2 = helper(A - 3, B - 1, dp);
        double val3 = helper(A - 2, B - 2, dp);
        double val4 = helper(A - 1, B - 3, dp);

        return dp[A][B] = (val1 + val2 + val3 + val4) * 0.25;

    }
    double soupServings(int n) {
        if(n >= 5000) return 1;
        n = (n + 24) / 25;
        vector<vector<double>>dp(n+1, vector<double>(n+1, -1));
        return helper(n, n, dp);
        // return 1;
    }
    


// 2D Tabulation causes MLE ----------------------------------------------------------------------------------------------------
    // double soupServings(int n) {
    //     vector<vector<double>>dp(n+1, vector<double>(n+1));
    //     for(int i = 0; i <= n; i++) {
    //         dp[0][i] = 1;
    //     }

    //     for(int i = 0; i <= n; i++) {
    //         dp[i][0] = 0;
    //     }

    //     dp[0][0] = 0.5;

    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= n; j++) {
    //             double val1 = 0, val2 = 0, val3 = 0, val4 = 0;
    //             if(i - 100 >= 0) 
    //                 val1 = dp[i - 100][j];
    //             else if(i - 100 < 0)
    //                 val1 = 1;

    //             if(i - 75 >= 0 && j - 25 >= 0)
    //                 val2 = dp[i - 75][j - 25];
    //             else if(i-75 < 0 && j-25 < 0)
    //                 val2 = 0.5;
    //             else if(i-75 < 0) 
    //                 val2 = 1;

    //             if(i - 50 >= 0 && j - 50 >= 0)
    //                 val3 = dp[i - 50][j - 50];
    //             else if(i-50 < 0 && j-50 < 0) 
    //                 val3 = 0.5;
    //             else if(i-50 < 0) 
    //                 val3 = 1;

    //             if(i - 25 >= 0 && j - 75 >= 0)
    //                 val4 = dp[i - 25][j - 75];
    //             else if(i-25 < 0 && j-75 < 0) 
    //                 val4 = 0.5;
    //             else if(i-25 < 0) 
    //                 val4 = 1;

    //             dp[i][j] = (val1 + val2 + val3 + val4) * 0.25;
    //         }
    //     }

    //     return dp[n][n];

    // }


    // double soupServings(int n) {
    //     vector<double>dp(n+1);
    //     for(int i = 0; i < n; i++) {
    //         double val1 = i-100 < 0 ? 0.25
    //     }
    // }
};