class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>>pal(n, vector<bool>(n, false));

        for(int len = 1; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(j - i + 1 <= 2) pal[i][j] = true;
                    else {
                        pal[i][j] = pal[i+1][j-1];
                    }
                }
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout<<pal[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        
        // TABULATION PART
        vector<int>dp(n, 0);
        for(int i = 0; i < n; i++) {
            if(pal[0][i]) {
                dp[i] = 0;
            }
            else{
                dp[i] = INT_MAX;
                for(int j = 0; j < i; j++) {
                    if(pal[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};