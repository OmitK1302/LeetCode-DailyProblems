class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i + j;
                }
                else if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = m;
        int j = n;

        string res;
        while(i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                res.push_back(str1[i - 1]);
                i -= 1;
                j -= 1;
            }

            else{
                if(dp[i - 1][j] < dp[i][j - 1]){
                    res.push_back(str1[i - 1]);
                    i -= 1;
                }
                else{
                    res.push_back(str2[j - 1]);
                    j -= 1;
                }
            }
        }

        while(i > 0){
            res.push_back(str1[i - 1]);
            i -= 1;
        }
        while(j > 0){
            res.push_back(str2[j - 1]);
            j -= 1;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};