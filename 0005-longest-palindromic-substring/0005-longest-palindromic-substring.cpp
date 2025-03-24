class Solution {
public:
    int maxLen = 0;
    int start = 0;
    
    void expand(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            if(right - left + 1 > maxLen){
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        // string ans = "";
        // int resLen = 0;
        for(int i = 0; i < s.length(); i++){
            expand(s, i, i);
            expand(s, i, i + 1);            
        }

        return s.substr(start, maxLen);
    }
};