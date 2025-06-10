class Solution {
public:
    vector<vector<int>>dp;
    int helper(int n, int curr, int clip) {
        if (curr == n) return 0;                 // Base case: no more operations needed
        if (curr > n) return INT_MAX;            // Invalid case

        if (dp[curr][clip] != -1) return dp[curr][clip];

        int copy = INT_MAX;
        if (curr != clip) {
            copy = helper(n, curr, curr);
        }

        int paste = helper(n, curr + clip, clip);

        int res = min(copy, paste);
        dp[curr][clip] = (res != INT_MAX ? res + 1 : INT_MAX); // +1 for the current operation
        return dp[curr][clip];
    }
    // int helper(int n, int curr, int clip) {
        
    //     if(n == curr) {
    //         return 1;
    //     }

    //     if(n < curr) {
    //         return INT_MAX;
    //     }

    //     if(dp[curr][clip] != -1) {
    //         return dp[curr][clip];
    //     }

    //     int copy = INT_MAX;
    //     if(curr != clip) {
    //         copy = helper(n, curr, curr);
    //     }
        
    //     int paste = helper(n, curr + clip, clip); 
        
    //     int currRes = min(copy, paste);

    //     dp[curr][clip] = currRes != INT_MAX ? currRes + 1 : INT_MAX;
    //     return dp[curr][clip];
    // }

    int minSteps(int n) {
        if(n == 1) return 0;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return 1+helper(n, 1, 1);
    }
};