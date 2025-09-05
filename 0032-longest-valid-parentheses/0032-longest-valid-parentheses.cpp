#include <string>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int left = 0, right = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left++;
            } 
            else {
                right++;
            }

            if (left == right) {
                maxLen = std::max(maxLen, 2 * right);
            } 
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } 
            else {
                right++;
            }

            if (left == right) {
                maxLen = std::max(maxLen, 2 * left);
            } 
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return maxLen;
    }
};