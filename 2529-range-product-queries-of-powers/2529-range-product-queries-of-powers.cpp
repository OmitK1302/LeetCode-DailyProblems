class Solution {
public:
    long long binPow(long long a, long long b, int m) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, int m) {
        return binPow(a, m - 2, m); // Fermat's little theorem
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        // Break n into powers of 2
        vector<long long> powers;
        for (int i = 30; i >= 0; i--) {
            if ((1 << i) <= n) {
                powers.push_back(1LL << i);
                n -= (1 << i);
            }
        }
        reverse(powers.begin(), powers.end());

        // Build prefix product
        vector<long long> prefix(powers.size());
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < powers.size(); i++) {
            prefix[i] = (prefix[i - 1] * (powers[i] % MOD)) % MOD;
        }

        // Answer queries
        vector<int> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                res.push_back(prefix[r]);
            } else {
                long long val = (prefix[r] * modInverse(prefix[l - 1], MOD)) % MOD;
                res.push_back((int)val);
            }
        }
        return res;
    }
};
