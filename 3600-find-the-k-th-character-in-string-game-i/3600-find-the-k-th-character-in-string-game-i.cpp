class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        
        while (word.length() < k) {
            string newStr;
            for (char ch : word) {
                if (ch == 'z') {
                    newStr += 'a';
                } else {
                    newStr += (ch + 1);
                }
            }
            word += newStr;
        }
        
        return word[k - 1];
    }
};