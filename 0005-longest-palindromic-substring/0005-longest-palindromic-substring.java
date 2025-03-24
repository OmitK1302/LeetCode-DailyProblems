public class Solution {
    // public String longestPalindrome(String s) {
    //     string ans = "";
    //     int resLen = 0;
    //     for(int i = 0; i < s.length(); i++){
    //         int left = i;
    //         int right = i;

    //         while(left >= 0 && right < s.length() && s[left] == s[right]){
    //             if(right - left + 1 > resLen){
    //                 resLen = right - left + 1;
    //                 ans = s.substr()
    //             }
    //             left--;
    //             right++;
    //         }
    //     }
    // }

    public String longestPalindrome(String s) {
        if (s.length() <= 1) {
            return s;
        }

        int maxLen = 1;
        String maxStr = s.substring(0, 1);

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + maxLen; j <= s.length(); j++) {
                if (j - i > maxLen && isPalindrome(s.substring(i, j))) {
                    maxLen = j - i;
                    maxStr = s.substring(i, j);
                }
            }
        }

        return maxStr;
    }

    private boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}