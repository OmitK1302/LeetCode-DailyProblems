class Solution {
public:
    bool isPrime(int num) {
        int cnt = 0;
        if(num == 0 || num == 1) return false;
        for(int i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                return false;
            }
        }

        return true;;
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