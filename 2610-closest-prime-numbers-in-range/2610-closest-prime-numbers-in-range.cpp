class Solution {
public:
    vector<int> sieveOfSomething(int left, int right) {
        vector<bool> marked(right + 1, true);
        vector<int> primes;
        marked[0] = marked[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (marked[i]) {
                for (int j = i * i; j <= right; j += i) {
                    marked[j] = false;
                }
            }
        }
        for (int i = left; i <= right; i++) {
            if (marked[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime = sieveOfSomething(left, right);

        if(prime.size() <= 1) return {-1, -1};
        vector<int>res;
        int minDiff = INT_MAX;
        for(int i = 0; i < prime.size() - 1; i++){
            if(prime[i + 1] - prime[i] < minDiff){
                res = {prime[i], prime[i + 1]};
                minDiff = min(minDiff, prime[i + 1] - prime[i]);
            }
        }

        return res;
    }
};