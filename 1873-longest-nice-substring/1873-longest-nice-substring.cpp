class Solution {
public:
    bool isNice(string str) {
        unordered_map<char, int>map;
        for(char& ch : str) {
            map[ch] = 1;
        }

        for(char& ch : str) {
            if(map[ch - 32] != 1 && map[ch+32] != 1) {
                return false;
            }
        }

        return true;
    }

    string longestNiceSubstring(string s) {
        string res;
        for(int i = 0; i < s.length(); i++) {
            // string curr;
            // unordered_map<char, int>charMap;
            // int count = 0;
            // int currMax = 0;
            for(int j = 0; j < s.length()-i; j++) {
                string substr = s.substr(i, j+1);
                if(isNice(substr) && substr.length() > res.length()) {
                    res = substr;
                }
            }
        }

        return res;
    }
};