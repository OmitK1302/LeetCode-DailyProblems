class Solution {
public:
    bool isPrime(int num) {
        int cnt = 0;
        for(int i = 1; i <= num; i++) {
            if(num % i == 0) {
                cnt++;
            }
        }

        return cnt == 2;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int& num : nums) {
            mp[num]++;
        }

        for(auto& it : mp) {
            if(isPrime(it.second)) return true;
        }
        return false;
    }
};