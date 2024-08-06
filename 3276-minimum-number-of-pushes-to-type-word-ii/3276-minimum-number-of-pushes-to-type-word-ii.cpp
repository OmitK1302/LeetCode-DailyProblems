class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26);
        for(char ch: word){
            freq[ch - 'a'] += 1;
        }

        sort(freq.rbegin(), freq.rend());
        // int t = 0;
        int i = 0;
        int ans = 0;
        while(i < 26 && freq[i] != 0){
            int t = i/8 + 1;
            ans += freq[i++] * (t);
        }

        return ans;
    }
};