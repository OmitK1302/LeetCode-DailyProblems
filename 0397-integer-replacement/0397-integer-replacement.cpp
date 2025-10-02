class Solution {
public:
    unordered_map<int, int> memo;
    int helper(long long n) {
        if (n == 1) {
            return 0;
        }

        if (memo.count(n)) {
            return memo[n];
        }

        int result;
        if (n % 2 == 0) {
            result = 1 + helper(n / 2);
        } else {
            result = 1 + min(helper(n + 1), helper(n - 1));
        }

        return memo[n] = result;
    }

    int integerReplacement(int n) {
        // vector<bool>visited(n+2, false);
        // visited[n] = true;

        return helper(n);
    }
};