class Solution {
public:
    // ------------------------------------------------------------OPTIMISED DP APPROACH-----------------------------------------------------------
    int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>pre(n+1, 0);
        vector<int>dp(n+1, 0);

        dp[1] = 1;
        pre[1] = 1;
        for(int i = 2; i <= n; i++) {
            int lLmt = (i - forget) <= 0 ? 0 : pre[i - forget];
            int rLmt = (i - delay) <= 0 ? 0 : pre[i - delay];

            dp[i] = (rLmt - lLmt + MOD) % MOD;
            pre[i] = ( (long long)pre[i-1] + dp[i] ) % MOD;

        }


        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }

        return ans;
        
    }
    
    
    // ------------------------------------------------------------BRUTE FORCE CAUSING TLE-----------------------------------------------------------
    // int peopleAwareOfSecret(int n, int delay, int forget) {
    //     queue<int>que;
    //     que.push(1);
    //     n -= 1;
    //     int nextEl = 2;
    //     unordered_map<int, int>mp;
    //     mp[1] = 1;
    //     while(n--) {
    //         int sz = que.size();

    //         for(int i = 0; i < sz; i++) {
    //             int curr = que.front();
    //             que.pop();

    //             if(mp[curr] == forget) {
    //                 mp.erase(curr);
    //             }
    //             else if(mp[curr] >= delay) {
    //                 que.push(curr);
    //                 que.push(nextEl);
    //                 mp[nextEl] = 1;
    //                 mp[curr]++;
    //                 nextEl++;
    //             }
    //             else{
    //                 que.push(curr);
    //                 mp[curr]++;
    //             }
    //         }
    //     }

    //     return que.size();
    // }
};