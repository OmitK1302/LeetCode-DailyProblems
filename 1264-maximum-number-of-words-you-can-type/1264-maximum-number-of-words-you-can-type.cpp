class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        unordered_map<char, bool>mp;
        for(char& ch : brokenLetters) {
            mp[ch] = true;
        }

        int res = 0;
        while(ss >> word) {
            bool good = true;
            for(char& ch : word) {
                if(mp.count(ch)) {
                    good = false;
                    break;
                }
            }
            if(good) res++;
        }


        return res;
    }
};