class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length() || s.empty() || t.empty()) return "";

        vector<int>mp(128, 0);
        for(char c : t){
            mp[c]++;
        }

        int start = 0, end = 0, minLen = INT_MAX, strt = 0, count = t.size();
        while(end < s.size()) {
            if(mp[s[end++]]-- > 0) count--;

            while(count == 0) {
                if(end - start < minLen) {
                    minLen = end - start;
                    strt = start;
                }

                if(mp[s[start++]]++ == 0) count++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(strt, minLen);
    }
};