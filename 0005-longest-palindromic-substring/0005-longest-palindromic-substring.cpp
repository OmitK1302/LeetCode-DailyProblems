class Solution {
public:
    string longestPalindrome(string s) {
        // Step 1: Preprocess the string
        string t = "^#";
        for (char c : s) {
            t += c;
            t += '#';
        }
        t += '$'; // end sentinel

        int n = t.size();
        vector<int> P(n, 0);
        int center = 0, right = 0;

        // Step 2: Manacher's main loop
        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;

            if (i < right)
                P[i] = min(right - i, P[mirror]);

            // Expand around center i
            while (t[i + (1 + P[i])] == t[i - (1 + P[i])])
                ++P[i];

            // Update center and right boundary
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }

        // Step 3: Find the max length and its center
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        // Step 4: Extract the result from original string
        int start = (centerIndex - maxLen) / 2; // remove '#' and '^'
        return s.substr(start, maxLen);
    }

};